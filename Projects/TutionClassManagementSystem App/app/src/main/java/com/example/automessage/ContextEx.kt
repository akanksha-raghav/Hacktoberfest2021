package com.example.automessage

import android.content.Context
import android.widget.Toast
import androidx.annotation.StringRes

fun Context.toast(msg: String) = Toast.makeText(this, msg, Toast.LENGTH_SHORT).show()
fun Context.toast(@StringRes msgRes: Int) = toast(getString(msgRes))