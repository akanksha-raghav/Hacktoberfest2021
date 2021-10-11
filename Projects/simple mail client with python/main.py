import smtplib
from email import encoders
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email.mime.multipart import MIMEMultipart

sender_email=input("enter sender email")
reciver_emil=input("add reciver email")
server=smtplib.SMTP_SSL('smtp.gmail.com',465)
# server.connect("smtp.gmail.com",465)
server.ehlo()
with open('pwd.txt','r') as f:
    pwd=f.read()
server.login(sender_email,pwd)
print(server.set_debuglevel(1))
msg= MIMEMultipart()
msg['From']='Dila'
msg['To']='reciver mail'
msg['Subject']='just a test'

with open('msg.txt','r') as f:
    message=f.read()
msg.attach(MIMEText(message,'plain'))

filename='hack - Copy.jpg'
attachment=open(filename,'rb')

p=MIMEBase('application','octet-stream')
p.set_payload(attachment.read())
encoders.encode_base64(p)
p.add_header('content-Disposition',f'attachment; filename={filename}')
msg.attach(p)
text=msg.as_string()
server.sendmail(sender_email,reciver_emil,text)

server.quit()