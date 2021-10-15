const express = require('express');
const mongoose = require('mongoose');
const createError = require('http-errors');

const app = express();
app.use(express.json());
app.use(express.urlencoded({ extended: false }));

mongoose.connect('mongodb://localhost/tddDB', {
    userNewUrlParser: true,
    userCreateIndex: true
})
    .then(() =>
        console.log(`Connected to MongoDB at mongodb://localhost/tddDB...`))
    .catch(err => {
        console.log('Failed to connect to MongoDB...');
        process.exit();
    });

const userRouter = require('./routes/user.route');

app.use('api/users', userRouter);

app.use((req, res, next) => {
    next(createError(404));
});

app.use((err, req, res, next) => {
    res.locals.message = err.message;

    res.status(err.status || 500);
    res.send(err);
});

module.exports = app;