package com.example.automessage

import android.app.AlertDialog
import android.content.DialogInterface
import android.content.Intent
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.isVisible
import androidx.recyclerview.widget.LinearLayoutManager
import com.google.firebase.database.*
import kotlinx.android.synthetic.main.activity_main.*
import kotlinx.android.synthetic.main.student_button.*

class MainActivity : AppCompatActivity(), StudentItemClicked {
    lateinit var ref: DatabaseReference
    lateinit var session: Session

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val userId = intent.getStringExtra("uid") ?: ""

        session = Session(this)
        addbutton.setOnClickListener {
            val intent = Intent(this, AddNewStudent::class.java)
            intent.putExtra("uid",userId)
            startActivity(intent)
        }
        ref = FirebaseDatabase.getInstance().getReference(userId)
        ref.addValueEventListener(object : ValueEventListener {
            override fun onDataChange(snapshot: DataSnapshot) {
                if (snapshot.exists()) {
                    wastetextview.isVisible = false
                    val tudulist = ArrayList<String>()
                    for (i in snapshot.children) {

                        var tudu = i.child("name").value.toString()
                        tudu = i.key.toString()
                        tudulist.add(tudu)
                    }
                    val adapter2 = adapter(tudulist, this@MainActivity, userId)
                    recyclerview.adapter = adapter2
                }
                else
                {
                    wastetextview.isVisible=true
                }
            }

            override fun onCancelled(error: DatabaseError) {
                TODO("Not yet implemented")
            }

        })
        // ref.child("mukul").child("fees").setValue("10000")
        recyclerview.layoutManager = LinearLayoutManager(this)
        // val items = fetchData()
        //  val adapter = adapter(items,this)
        //recyclerview.adapter = adapter

        tvLogout.setOnClickListener {
            AlertDialog.Builder(this)
                .setTitle("Log Out")
                .setMessage("Are you sure you want to Log Out ?") // Specifying a listener allows you to take an action before dismissing the dialog.
                // The dialog is automatically dismissed when a dialog button is clicked.
                .setPositiveButton(android.R.string.yes,
                    DialogInterface.OnClickListener { dialog, which ->
                        session.logoutUser()
                        finish()
                        // Continue with delete operation
                    }) // A null listener allows the button to dismiss the dialog and take no further action.
                .setNegativeButton(android.R.string.no, null)
                .setIcon(android.R.drawable.ic_dialog_alert)
                .show()

        }

    }

//    private fun fetchData() : ArrayList<String>
//    {
//        val list = ArrayList<String>()
//            for(i in 0 until 100){
//               list.add("Item $i")
//            }
//
//
//        return  list
//    }

    override fun onItemClicked(item: String) {
        //   Toast.makeText(this,"clicked $item",Toast.LENGTH_SHORT).show()
        var intent = Intent(this, SeeDetailsOfStudent::class.java)
        intent.putExtra("id", item)
        startActivity(intent)
    }
}