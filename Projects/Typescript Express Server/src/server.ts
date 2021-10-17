import express, {Application, Request, Response, NextFunction} from 'express';
import path from 'path';

const app: Application = express();


app.get('/', (req: Request, res: Response, next: NextFunction) => {
    res.sendFile(path.join(__dirname, 'index.html'))
})

const PORT = process.env.PORT ? process.env.PORT : 5000;
app.listen(PORT, () => console.log(`server running on ${PORT}`))