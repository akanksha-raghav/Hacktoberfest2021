package com.example.automessage

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.google.firebase.database.DatabaseReference
import com.google.firebase.database.FirebaseDatabase
import kotlinx.android.synthetic.main.activity_add_new_student.*

class AddNewStudent : AppCompatActivity() {
    lateinit var mdb : DatabaseReference
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_add_new_student)
        val userid = intent.getStringExtra("uid").toString()
        mdb = FirebaseDatabase.getInstance().getReference(userid)
        donebutton.setOnClickListener {
            val name=newStudentName.text.toString()
            val course = newStudentCourse.text.toString()
            val DOA = newStudentDOJ.text.toString()
            val fee= newStudentFees.text.toString()
            val phone = newStudentPhone.text.toString()
            val inputResult = validateInput(name,course,DOA,fee,phone)
            inputResult?.let {
                toast(inputResult)
                return@setOnClickListener
            }
            val id : String?= mdb.push().key
            mdb = mdb.child(id!!)
            val studentname = newStudentName.text.toString().capitalize()
            val studentcourse = newStudentCourse.text.toString().capitalize()
           // mdb.child("id").setValue(id!!)
            mdb.child("name").setValue(studentname)
            mdb.child("course").setValue(studentcourse)
            mdb.child("date of joining").setValue(newStudentDOJ.text.toString())
            mdb.child("Fees to Collect").setValue(newStudentFees.text.toString())
            mdb.child("phone").setValue(newStudentPhone.text.toString())
            onBackPressed()
        }
    }
    private fun validateInput(name: String, course: String,DOA : String, Fee : String, Phoneno : String): String? {

        if (name.isEmpty()) {
            return "Email cannot be empty"
        }


        if (course.isEmpty()) {
            return "Password cannot be empty"
        }

        if(DOA.isEmpty())
        {
            return "Please enter data of joining"
        }
        if(Fee.isEmpty())
        {
            return "please enter fees due"
        }
        if(Phoneno.isEmpty())
        {
            return "Phone Number can not be empty"
        }

        return null
    }
}