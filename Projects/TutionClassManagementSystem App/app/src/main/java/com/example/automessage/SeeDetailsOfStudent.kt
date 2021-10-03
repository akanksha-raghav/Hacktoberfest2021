package com.example.automessage

import android.content.Intent
import android.icu.number.IntegerWidth
import android.net.Uri
import android.opengl.Visibility
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import androidx.core.view.isVisible
import com.google.firebase.database.*
import kotlinx.android.synthetic.main.activity_main.*
import kotlinx.android.synthetic.main.activity_see_details_of_student.*

class SeeDetailsOfStudent : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_see_details_of_student)
        val session : Session = Session(this)
        val userid = session.getUserid()
        var id : String? = intent.getStringExtra("id")
        val ref = FirebaseDatabase.getInstance().getReference(userid)
        addlayout.isVisible=false
        addlayout.isClickable=false
//       ref.child(id!!).get().addOnSuccessListener {
//           detstudentname.text=it.child("name").value.toString().capitalize()
//           detstudentcourse.text=it.child("course").value.toString().toUpperCase()
//           detstudentDOJ.text=it.child("date of joining").value.toString()
//           detstudentFees.text="Fees To Be Collected : "+it.child("Fees to Collect").value.toString()
//       }
        ref.child(id!!).addValueEventListener(object : ValueEventListener
        {
            override fun onDataChange(it: DataSnapshot) {
                detstudentname.text="Student Name: "+ it.child("name").value.toString().capitalize()
                detstudentcourse.text="Course: "+it.child("course").value.toString().toUpperCase()
                detstudentDOJ.text="Date of Joining: "+it.child("date of joining").value.toString()
                detstudentFees.text="Fees To Be Collected : "+it.child("Fees to Collect").value.toString()
                detstudentphone.text="Phone Number: "+it.child("phone").value.toString()
                showFeeEvents(id,userid)
            }
            override fun onCancelled(error: DatabaseError) {
                TODO("Not yet implemented")
            }

        })

        remindbutton.setOnClickListener {
            ref.child(id).get().addOnSuccessListener {

                val uri = Uri.parse("smsto:${it.child("phone").value.toString()}")
                val intent = Intent(Intent.ACTION_SENDTO, uri)
                intent.putExtra("sms_body", "Dear ${it.child("name").value.toString()}, your fees Rs. ${it.child("Fees to Collect").value.toString()} will become due tomorrow, kindly pay it\nThank You")
                startActivity(intent)
            }


        }
        addfeeEvent.setOnClickListener {
            addfeeEvent(id,userid)
        }
//        detstudentfeeEvents.setOnClickListener {
//            showFeeEvents(id!!)
//        }
    }

    private fun showFeeEvents(id: String, userid : String) {
        textView2.isVisible=true
        textView2.setText("")
        val ref = FirebaseDatabase.getInstance().getReference(userid).child(id)
        ref.child("Fee Events").get().addOnSuccessListener {
          val childf= it.children
            childf.forEach{
                textView2.text = "\n"+it.value.toString()+textView2.text.toString()
            }
        }
    }

    private fun addfeeEvent(id: String,userid: String) {
        addlayout.isVisible = true
        addlayout.isClickable =true
        cancel.setOnClickListener {
//        detstudentfeeEvents.isVisible=true
//        detstudentfeeEvents.isClickable=true
        addlayout.isVisible=false
        addlayout.isClickable=false
        }

        val ref = FirebaseDatabase.getInstance().getReference(userid).child(id)
        done.setOnClickListener {
            val rid= ref.push().key
            ref.child("Fee Events").child(rid.toString()).setValue("       "+feeupevent.text.toString() + "                       "+ messupevent.text.toString())
            var newfee =10

            ref.get().addOnSuccessListener {
               var tudunewfee = it.child("Fees to Collect").value.toString()
                var tuduint = Integer.parseInt(tudunewfee)

                newfee =(tuduint+feeupevent.text.toString().toInt())
                var mdb = FirebaseDatabase.getInstance().getReference(userid).child(id!!)
                mdb.child("Fees to Collect").setValue(newfee.toString())

            addlayout.isClickable=false
            addlayout.isVisible=false
            feeupevent.setText("")
            messupevent.setText("")
//            detstudentfeeEvents.isVisible=true
//            detstudentfeeEvents.isClickable=true
            }
//            addlayout.isClickable=false
//            addlayout.isVisible=false
//            feeupevent.setText("")
//            messupevent.setText("")
//            detstudentfeeEvents.isVisible=true
//            detstudentfeeEvents.isClickable=true

        }

    }
}