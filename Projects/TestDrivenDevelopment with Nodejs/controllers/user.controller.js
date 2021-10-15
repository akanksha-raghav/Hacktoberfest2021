const mongoose = require('mongoose');
const { User } = require('../models/user.model');

const getAllUsers = async (req, res) => {
    let users = await User.find({});
    return res.send(users);
};

const getUser = async (req, res) => {
    let userId = req.params.id;
    if (!mongoose.Types.ObjectId.isValid(userId))
        return res.status(400).send('Invalid object id');
    let user = await User.findById(userId);
    if (!user)
        return res.status(404).send('User not found');
    return res.send(user);
};

const createUser = async (req, res) => {
    console.log(req.body);
    let user = new User({
        name: req.body.name,
        email: req.body.email,
        gender: req.body.gender
    });

    await user.save();
    return res.send(user);
};

const updateUser = async (req, res) => {
    let userId = req.params.id;
    User.findOneAndUpdate(userId, req.body, { new: true })
        .then(user => {
            return res.send(user);
        })
        .catch(err => {
            return res.status(500).send(err);
        });
};

const deleteUser = async (req, res) => {
    let userId = req.params.id;
    await User.findByIdAndDelete(userId);
    return res.send('User deleted');
};

module.exports = { deleteUser, updateUser, createUser, getAllUsers, getUser }
