class Node:  #This can be like database
    #It is written for node in Posting list
    def __init__(self,data):
        self.data=data
        self.next=None
class LinkedList:       #This can be like database
    #This is the Linked list for posting list
    #This contains double pointer to reduce time complexity
    def __init__(self):
        self.head=None
        self.tail=None
    def addNode(self,data):
        if self.head==None:
            self.head=Node(data)
            self.tail=self.head
        else:
            self.tail.next=Node(data)
            self.tail=self.tail.next

    def addNode_ord(self, data):
        if self.head == None:
            self.head = Node(data)
            self.tail = self.head
        else:
            he=self.head
            ta=self.tail
            if(data<he.data):
                self.head=Node(data)
                self.head.next=he
            else:
                while(he.next!=None):
                    if(data<he.next.data):
                        temp=he.next
                        he.next=Node(data)
                        he.next.next=temp
                    if(data==he.next.data):
                        return 0
                    he=he.next
                if he.next==None:
                    he.next=Node(data)
                    self.tail=Node
    def printList(self):
        temp=self.head
        st=""
        while(temp):
            st=st+"->"+str(temp.data)
            temp=temp.next
        return st
    def consList(self):
        temp = self.head
        st = ""
        while (temp):
            print("->",str(temp.data),end=" ")
            temp = temp.next

import re
dict = {}
ind_sta=101
ind_end=282
old_ind=ind_sta
# dict is used where term is used as identifier and value will be array of freq and linked list pointer

for ind in range(ind_sta,ind_end):
    f_loc = "ths-181-dataset/th-dataset/"
    fp = open(f_loc + str(ind) + ".txt", "r", encoding="utf8")
    c = fp.read().lower()
    c_l=re.split("[, -.]",c)
    #c_l = c.split(" ")
    for i, te in enumerate(c_l):
        c_l[i] = (''.join(filter(str.isalnum, te))).strip()
    c_s = set(c_l)
    c_s.remove('')
    fp.close()
    for term in c_s:
        if term not in dict:
            dict[term]=[1,LinkedList()]
            dict.get(term)[1].addNode(ind)
        else:
            dict.get(term)[0]+=1
            dict.get(term)[1].addNode(ind)

fp=open("Assign012019114-output.txt","w",encoding="utf-8")
for i,j in dict.items():
    freq="freq: "+str(j[0])
    fp.write(i.ljust(20)+freq.ljust(10)+j[1].printList()+"\n")
    # print(i.ljust(20),end="")
    # print(dict[i][0],end=" ")
    # dict[i][1].printList()
fp.close()
