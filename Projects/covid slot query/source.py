# -*- coding: utf-8 -*-
"""
Created on Fri May 14 15:27:47 2021

@author: Kunwar Pratap Singh
"""
import json
import requests 


def jprint(obj):
    # create a formatted string of the Python JSON object
    text = json.dumps(obj, sort_keys=True, indent=4)
    print(type(text))
    print(text)

def call(date, district_id):

    url = "https://cdn-api.co-vin.in/api/v2/appointment/sessions/public/findByDistrict"

    payload={
            "district_id" : str(district_id) , 
            "date" : date
        }
    headers = {
      'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.93 Safari/537.36'
    }

    response = requests.request("GET", url, headers=headers, params = ( payload ))

    print(response)

    if response.status_code == 200 :
        d = response.json() 
        for elem in d["sessions"] :
            if elem['available_capacity_dose1']:
                print('dose 1: ', elem['address'] , elem['min_age_limit'], sep = ' ')

        for elem in d["sessions"] :
            if elem['available_capacity_dose2']:
                print('dose 2: ', elem['address'] , elem['min_age_limit'], sep = ' ')
          
            
    else :
         print("error")


    

while(1):
    print("enter the date in dd-mm-yyyy: " )
    date = input()
    print("ennter district id: \n", "take ref: https://github.com/bhattbhavesh91/cowin-vaccination-slot-availability/blob/main/district_mapping.csv")
    d_id = input()

    call(date, d_id)
