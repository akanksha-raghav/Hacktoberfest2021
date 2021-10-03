package com.example.automessage

import android.app.AlertDialog
import android.content.Context
import android.content.DialogInterface
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import com.google.firebase.database.FirebaseDatabase
import kotlinx.android.synthetic.main.student_button.view.*


class adapter(val items : ArrayList<String>, private val listener : StudentItemClicked, private val userId: String) : RecyclerView.Adapter<StudentViewHolder>() {
    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): StudentViewHolder {
      val view = LayoutInflater.from(parent.context).inflate(R.layout.student_button,parent,false)
      val viewHolder = StudentViewHolder(view)
        view.textView.setOnClickListener{
          listener.onItemClicked(items[viewHolder.adapterPosition])
      }

        view.deletebutton.setOnClickListener{
            val ref = FirebaseDatabase.getInstance().getReference(userId).child(items[viewHolder.adapterPosition])
            ref.child("name").get().addOnSuccessListener {

                AlertDialog.Builder(parent.context)
                    .setTitle("Delete Student")
                    .setMessage("Are you sure you want to delete all the data of ${it.value.toString()} ?") // Specifying a listener allows you to take an action before dismissing the dialog.
                    // The dialog is automatically dismissed when a dialog button is clicked.
                    .setPositiveButton(android.R.string.yes,
                        DialogInterface.OnClickListener { dialog, which ->
                            ref.removeValue()
                            items.removeAt(viewHolder.adapterPosition)
            notifyItemRemoved(viewHolder.adapterPosition)
            notifyItemRangeChanged(viewHolder.adapterPosition,items.size)
                            // Continue with delete operation
                        }) // A null listener allows the button to dismiss the dialog and take no further action.
                    .setNegativeButton(android.R.string.no, null)
                    .setIcon(android.R.drawable.ic_dialog_alert)
                    .show()
            }


//            var ref = FirebaseDatabase.getInstance().getReference("students")
//            ref.child(items[viewHolder.adapterPosition]).removeValue()
//          items.removeAt(viewHolder.adapterPosition)
//            notifyItemRemoved(viewHolder.adapterPosition)
//            notifyItemRangeChanged(viewHolder.adapterPosition,items.size)

        }
       return viewHolder
    }

    override fun onBindViewHolder(holder: StudentViewHolder, position: Int) {

        val ref = FirebaseDatabase.getInstance().getReference(userId)
        val currentItem = items[position]
        ref.child(currentItem).get().addOnSuccessListener {
           holder.titleView.text=  (position+1).toString() + ". "+ it.child("name").value.toString().capitalize()
        }
       // holder.titleView.text = currentItem.toString()
    }

    override fun getItemCount(): Int {
       return items.size
    }
}
class StudentViewHolder(itemview: View) : RecyclerView.ViewHolder(itemview)
{
    val titleView : TextView = itemview.findViewById(R.id.textView)
}

interface StudentItemClicked{
    fun onItemClicked(item : String)
}



//    class adapter(val items : MutableMap<String,String>, private val listener : StudentItemClicked) : RecyclerView.Adapter<StudentViewHolder>() {
//    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): StudentViewHolder {
//      val view = LayoutInflater.from(parent.context).inflate(R.layout.student_button,parent,false)
//      val viewHolder = StudentViewHolder(view)
//        view.textView.setOnClickListener{
//          listener.onItemClicked(items.[viewHolder.adapterPosition])
//      }
//        view.deletebutton.setOnClickListener{
//          items.removeAt(viewHolder.adapterPosition)
//            notifyItemRemoved(viewHolder.adapterPosition)
//            notifyItemRangeChanged(viewHolder.adapterPosition,items.size)
//            val ref = FirebaseDatabase.getInstance().getReference("students")
//        }
//       return viewHolder
//    }
//
//    override fun onBindViewHolder(holder: StudentViewHolder, position: Int) {
//        val currentItem = items[position]
//        holder.titleView.text = currentItem
//    }
//
//    override fun getItemCount(): Int {
//       return items.size
//    }
//}
//class StudentViewHolder(itemview: View) : RecyclerView.ViewHolder(itemview)
//{
//    val titleView : TextView = itemview.findViewById(R.id.textView)
//}
//
//interface StudentItemClicked{
//    fun onItemClicked(item : String)
//}