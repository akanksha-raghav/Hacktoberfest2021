#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Family{       // A class whose objects will store one triple each 
	public:
	ll val1, val2;
	Family *next;
};

void printTriples(Family *Family){         // Function to print all the triples
	while (Family != NULL){
		cout<<" ("<<Family->val1<<", "<<Family->val2<<")";
		Family = Family->next;
	}
    cout<<"\n";
}

bool addTriple(Family** mom, ll data1, ll data2){      // Function to add a triple
    int chk=1;
	Family* baby = new Family();            // Creating a new baby, i.e. a new triple

	Family *last = *mom; 
    Family *check = *mom;
    while(check!=NULL){
        if(check->val1 == data2){           // Checking for any twin of the found triple
            chk=0;
        }
        check = check->next;
    }
    if(chk == 0){           // Mission abort and return if the twin of a triple already exists in the family
        return false;
    }

	baby->val1 = data1;
    baby->val2 = data2;
	baby->next = NULL;

	if (*mom == NULL){          // Make this baby 1st triple if no previous triples exist
		*mom = baby;
		return true;
	}

	while (last->next != NULL){
		last = last->next;
    }

	last->next = baby;          // New triple added to the family
	return true;
}

void findPythagoreanTriples(ll tmin, ll tmax){         // Function to find Pythagorean Triples 
    ll i,j;
    ll max=sqrt(tmax), min=sqrt(tmin);

    if(min*min<tmin){
        ++min;
    }

    Family *TripleRecord[max-min+1];           // Declaring an array of triple records (families)
    int records[max-min+1];

    for(i=min; i<=max; ++i){
        TripleRecord[i-min]=NULL;
        records[i-min]=0;   
        for ( j = 1; j < i; ++j){
            ll diffSq = i*i - j*j;
            if(ll(sqrt(diffSq))==sqrt(diffSq)){         // New possible triple found (a = j, b = ll(sqrt(diffSq)))
                if(addTriple(&TripleRecord[i-min], j, ll(sqrt(diffSq)))){     // Add the new triple to the family.
                ++records[i-min];                           // Increment the no. of family members (no. of triples)
                }
            }
        } 
        if(records[i-min]!=0){
            cout<<i<<" -> "<<records[i-min]<<" pair(s) found\n";
         printTriples(TripleRecord[i-min]);       // Print the triples of each family
            cout<<" \n";
        } 
        else{
            cout<<i<<" -> no pairs found\n";
        }  
    }
}


int main(){
    ll lmin, lmax;
    cout<<"Enter the lower limit (non-negative): ";        // Enter the Lower limit of 'c'
    cin>>lmin;
    cout<<"Enter the upper limit (non-negative): ";
    cin>>lmax;
    if(lmin>=0 && lmax>=0){
    findPythagoreanTriples(lmin, lmax);    // Enter the Upper limit of 'c'
    }
    else{
        cout<<"Both numbers must be non-negative!\n";
    }
    
    return 0;
}