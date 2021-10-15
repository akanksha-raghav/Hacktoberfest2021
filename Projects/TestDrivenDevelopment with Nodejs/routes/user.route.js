const express = require('express');
const router = express.Router();
const controller = require('../controllers/user.controller');

router
    .route('/')
    .get(controller.getAllUsers)
    .post(controller.createUser);

router
    .route('/id:')
    .get(controller.getUser)
    .put(controller.updateUser)
    .delete(controller.deleteUser);

module.exports = router;