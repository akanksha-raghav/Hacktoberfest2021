package com.example.automessage

import android.content.Intent
import android.os.Bundle
import android.text.style.ClickableSpan
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.google.firebase.auth.FirebaseAuth
import kotlinx.android.synthetic.main.activity_login_signup.*

class LoginSignupActivity : AppCompatActivity() {
    lateinit var session: Session
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_login_signup)
        session = Session(this)
        if (session.isLoggedin()) {
            //toast("called is logged in")
            var intent = Intent(applicationContext, MainActivity::class.java)
            intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK)
            intent.putExtra("uid", session.getUserid())
            startActivity(intent)
            finish()
        }
        var mAuth = FirebaseAuth.getInstance()

        signupBtn.setOnClickListener {
            var intent = Intent(this, SignUpActivity::class.java)
            startActivity(intent)
        }
        loginBtn.setOnClickListener {
            var email = login_emailid.text.toString().trim()
            var pass = login_password.text.toString().trim()

            val inputResult = validateInput(email, pass)
            inputResult?.let {
                toast(inputResult)
                return@setOnClickListener
            }

            mAuth.signInWithEmailAndPassword(email, pass).addOnCompleteListener { task ->
                if (task.isSuccessful) {
                    toast("Logged in Successfully")
                   // Toast.makeText(this, "tudu tudu", Toast.LENGTH_SHORT).show()
                    val usid = mAuth.currentUser!!.uid.toString()
                    //toast(usid)
                    session.createLoginSession(usid)
                    val i = Intent(this, MainActivity::class.java)
                    i.putExtra("uid", usid)
                    startActivity(i)
                    finish()
                } else {
                    toast("${task.exception?.message}")
                }
            }
        }
    }

    private fun validateInput(email: String, password: String): String? {

        if (email.isEmpty()) {
            return "Email cannot be empty"
        }

        if (!email.isEmailValid()) {
            return "Email is not valid"
        }

        if (password.isEmpty()) {
            return "Password cannot be empty"
        }

        if (password.length < 8 || password.length >= 20) {
            return "Password must be at least 8 characters"
        }

        return null
    }


}

