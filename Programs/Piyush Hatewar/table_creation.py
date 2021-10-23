import mysql.connector as myconn

bank_db = myconn.connect (
  host="localhost",
  user="user_name",
  password="password_of_your_database",
  database = "pie_bank" )

bank_cur = bank_db.cursor()

bank_cur.execute("Create table Bank_Users (User_id int AUTO_INCREMENT PRIMARY KEY ,First_Name VARCHAR(100) ,Last_Name Varchar(100) ,Address Varchar(100) ,Mobile_No Varchar(20) , Card_no Varchar(16),Pin Varchar(6) ,Balance int , Opening_Date Varchar(15), Acc_Status varchar(2))")

bank_cur.execute("Create table Complaints (Number int AUTO_INCREMENT PRIMARY KEY , Complaint Varchar(500))")

bank_cur.execute("Create table Loan_Users (User_id int, Loan_approved int, EMI Varchar(15) , Total_repay_amount int, Loan_issue_date Varchar(15), Loan_Period int , Remaining_Period int , Amount_Repayed int , Loan_Status varchar(7))")

bank_cur.execute("Create table Closed_Bank_Users (User_id int ,First_Name VARCHAR(100) ,Last_Name Varchar(100) ,Address Varchar(100) ,Mobile_No Varchar(20) , Card_no Varchar(16),Pin Varchar(6) ,Balance int , Opening_Date Varchar(15), Closed_Date Varchar(15), Acc_Status varchar(2))")

bank_cur.execute("Insert into Bank_Users(First_Name,Last_Name,Address,Mobile_No,Pin,Balance,Acc_Status) Values ('Bank','Account','Reshimbagh','1002','9182',1000000000,'o')")

bank_cur.execute("Create table trans_history(User_id int, Transaction int, Trans_status varchar(4), Date varchar(15))")

bank_db.commit()