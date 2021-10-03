package com.example.automessage

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.text.Spannable
import android.text.SpannableString
import android.text.method.LinkMovementMethod
import android.text.style.ClickableSpan
import android.view.View
import android.widget.Toast
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.auth.FirebaseUser
import com.google.firebase.auth.ktx.auth
import com.google.firebase.database.FirebaseDatabase
import com.google.firebase.ktx.Firebase
import kotlinx.android.synthetic.main.activity_sign_up.*

class SignUpActivity : AppCompatActivity() {
    private lateinit var auth: FirebaseAuth
    lateinit var session: Session
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_sign_up)
        makeclickable()
        session = Session(this)
        auth = Firebase.auth
        val mAuth=FirebaseAuth.getInstance()
        signUpBtn.setOnClickListener {

            val email = userEmailId.text.toString()
            val password = password.text.toString()
            val confirmpass = confirmPassword.text.toString()

            val inputResult =  validateInput(email, password,confirmpass)
            inputResult?.let {
                toast(inputResult)
                return@setOnClickListener
            }

            mAuth.createUserWithEmailAndPassword(email, password).addOnCompleteListener(this){
                val usid = mAuth.currentUser?.uid.toString()
                session.createLoginSession(usid)
                val ref = FirebaseDatabase.getInstance().getReference(usid)
                val intent = Intent(this,MainActivity::class.java)
                intent.putExtra("uid",usid)
                startActivity(intent)
                toast("Signed Up successfully")
                finish()
            }
        }
    }
    private fun makeclickable()
    {
        val spannableString = SpannableString(already_user.text)
        val clickableSpan = object : ClickableSpan()
        {
            override fun onClick(widget: View) {
                onBackPressed()
            }
        }
       spannableString.setSpan(clickableSpan,22,32, Spannable.SPAN_INCLUSIVE_INCLUSIVE)
        already_user.text = spannableString
        already_user.movementMethod = LinkMovementMethod.getInstance()
    }

    private fun validateInput(email: String, password: String,confirmpass : String): String?{

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
        if(confirmpass!=password)
        {
            return "Password and Confirm Password should be same"
        }
        return null
    }

}