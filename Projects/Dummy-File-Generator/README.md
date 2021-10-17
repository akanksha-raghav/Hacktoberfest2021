# dfgen

[dfgen](https://www.npmjs.com/package/dfgen) is a NodeJS command line interface that creates dummy files for testing purpose.

## Installation

```bash
# clone the repository
git clone https://github.com/0kyn/dfgen

cd dfgen

# local
npm install --save-dev dfgen

# global
npm install --global dfgen
```

## Usage

```bash
# local
npx dfgen --help

# global
dfgen --help
```

### Generate a blank pdf file
```bash
dfgen --type pdf 
```

### Generate a pdf file with custom text

```bash
dfgen --type pdf --text-content "This is a text content"
```

### Generate an image with custom text

```bash
dfgen --type png --text-content "This is a text inside a png"

dfgen --type jpg --text-content "This is a text inside a jpg"
```

### Generate a corrupted file

```bash
# you can basicly generate a file with a wrong extension
dfgen --type jpg --output image.gif

# you can also generate a file with an invalid signature
dfgen --type jpg -cs invalid # this will replace the 4 first bytes with 0x00 0x01 0x02 0x03
```

## License

[MIT](https://choosealicense.com/licenses/mit/)