package com.example.automessage

import android.content.Context
import android.content.Intent
import android.content.SharedPreferences

class Session {
    lateinit var pref: SharedPreferences
    lateinit var editor: SharedPreferences.Editor
    lateinit var con: Context
    var PRIVATEMODE: Int = 0

    constructor(con: Context) {
        this.con = con
        pref = con.getSharedPreferences(PREF_NAME, PRIVATEMODE)
        editor = pref.edit()
    }

    companion object {
        val PREF_NAME = "Login_Preference"
        val Is_login = "isLoggedIn"
        val uid = "userId"
    }

    fun createLoginSession(usid: String) {
        editor.putBoolean(Is_login, true)
        editor.putString(uid, usid)
        editor.commit()
    }

//    fun checkLogin() {
//        if (!this.isLoggedin()) {
//            var i: Intent = Intent(con, LoginSignupActivity::class.java)
//            i.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP)
//            i.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK)
//            con.startActivity(i)
//        }
//    }

    fun getUserid(): String {
        var usid: String
        usid = pref.getString(uid, null).toString()
        return usid
    }

    fun logoutUser() {
        editor.clear()
        editor.commit()
        val i: Intent = Intent(con, LoginSignupActivity::class.java)
        i.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP)
        i.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK)
        con.startActivity(i)

    }

    fun isLoggedin(): Boolean {
        return pref.getBoolean(Is_login, false)
    }
}
