"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const express_1 = __importDefault(require("express"));
const path_1 = __importDefault(require("path"));
const app = (0, express_1.default)();
app.get('/', (req, res, next) => {
    res.sendFile(path_1.default.join(__dirname, 'index.html'));
});
const PORT = process.env.PORT ? process.env.PORT : 5000;
app.listen(PORT, () => console.log(`server running on ${PORT}`));
