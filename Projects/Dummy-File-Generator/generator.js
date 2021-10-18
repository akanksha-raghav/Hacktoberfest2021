const fs = require('fs')
const { createCanvas } = require('canvas')
const GifEncoder = require('gif-encoder')

class Generator {
    constructor(config) {
        this.config = config

        this.config.mimeType = this._getMimeType(this.config.type)
        this.config.output = this.config.output ?? `${this._setOutputFilename('dummy')}.${this.config.type}`
        this.config.fontSize = 25

        const widthHeightSplit = this.config.widthHeight.split('/')
        this.config.width = parseInt(widthHeightSplit[0])
        this.config.height = parseInt(widthHeightSplit[1])
    }

    _getMimeType(fileType) {
        const mimeType = {
            pdf: 'application/pdf',
            jpg: 'image/jpeg',
            png: 'image/png',
            gif: 'image/gif'
        }

        return mimeType[fileType]
    }

    _getFileSignature(fileType) {
        const fileSignature = {
            invalid: [0, 1, 2, 3],
            pdf: [0x25, 0x50, 0x44, 0x46],
            jpg: [0xFF, 0xD8, 0xFF],
            png: [0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A],
            gif: [0x47, 0x49, 0x46]
        }

        return fileSignature[fileType]
    }

    _setOutputFilename(prefix) {
        const date = new Date()

        const dateIsoSplit = new Date(date.getTime() - (date.getTimezoneOffset() * 60000)).toISOString().split('T')

        const dateFormat = dateIsoSplit[0]
        const hourFormat = dateIsoSplit[1].match(/(.*)\./)[1].replace(/:/g, '')

        const outputFilename = `${prefix}-${dateFormat}-${hourFormat}`

        return outputFilename
    }

    _createCanvas(width, height, type = null) {
        const canvas = createCanvas(width, height, type)
        const context = canvas.getContext('2d')
        context.fillStyle = '#fff'
        context.fillRect(0, 0, width, height)

        if (this.config.textContent) {
            const textContent = this.config.textContent
            context.font = `bold ${this.config.fontSize}pt Arial`
            context.fillStyle = "#000"
            context.textAlign = 'center'
            context.fillText(textContent, width / 2, height / 2)
        }

        this.canvasContext = context
        this.canvasBuffer = canvas.toBuffer(this.config.mimeType)
    }

    _canWriteFile(filename) {
        return !fs.existsSync(filename) || this.config.force
    }

    _genPdf() {
        this._createCanvas(595, 842, 'pdf')
        fs.writeFileSync(this.config.output, this.canvasBuffer)
    }

    _genImage() {
        const width = this.config.width
        const height = this.config.height

        this._createCanvas(width, height)

        if (this.config.type !== 'gif') {
            fs.writeFileSync(this.config.output, this.canvasBuffer)
        } else {
            const gif = new GifEncoder(width, height)
            const pixels = this.canvasContext.getImageData(0, 0, width, height).data
            const file = fs.createWriteStream(`${this.config.output}`)

            gif.pipe(file)
            gif.writeHeader()
            gif.addFrame(pixels)
            gif.finish()
        }
    }

    corruptFile(filename, signatureType) {
        const tmpFile = 'file.tmp'
        const writeStream = fs.createWriteStream(tmpFile, { flags: 'w+' })
        const signature = Buffer.from(this._getFileSignature(signatureType))

        const readStream = fs.createReadStream(filename, { start: signature.length + 1 })
        readStream.pipe(writeStream)

        writeStream.on('finish', () => {
            const readStream2 = fs.createReadStream(tmpFile)
            const writeStream2 = fs.createWriteStream(filename, { start: 0, flags: 'r+' })
            writeStream2.write(signature)
            readStream2.pipe(writeStream2)

            writeStream2.on('finish', () => {
                fs.unlinkSync(tmpFile)
            })
        })
    }

    make() {
        if (this._canWriteFile(this.config.output)) {
            switch (this.config.type) {
                case 'pdf':
                    this._genPdf()
                    break
                case 'jpg':
                case 'png':
                case 'gif':
                    this._genImage()
                    break
                default:
                    break
            }
            if (this.config.corruptSignature) {
                this.corruptFile(this.config.output, this.config.corruptSignature)
            }
        } else {
            console.error(`File exists: ${this.config.output}. Use --force option to override file.`)
        }
    }
}

module.exports.Generator = Generator