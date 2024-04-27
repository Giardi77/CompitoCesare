#include <iostream>
#include <string>
using namespace std;

string alfabet = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// way : true - encrypt, false - decrypt
char replace(char mex, char key,bool way){
    int m_value,k_value,r_value;
    char replaced;

    // retrieve char of mex value
    for(int x = 0; x <= 26 ; x++){
        if(alfabet[x] == mex){
            m_value = x;
            break;
        }
    }
    // retrie char of key value 
    for(int x = 0; x <= 26 ; x++){
        if(alfabet[x] == key){
            k_value = x;
            break;
        }
    }

    if (way == true){
        r_value = m_value + k_value;

        if (r_value > 26){
            r_value = r_value - 27;
        }
    }

    if (way == false){
        r_value = m_value - k_value;

        if (r_value < 0){
            r_value = r_value + 27;
        }
    }

    replaced =  alfabet[r_value] ;



    return replaced;
}

string algorithm(string mex,string key, bool way){
    int m_size = mex.size();
    int k_size = key.size();
    string processedmex = "";
    string key_on_mex = "";
    int c_counter = 0;

    for(int x = 0; x < m_size ; x++){
        key_on_mex += key[c_counter];
        c_counter++;
        if (c_counter == k_size)
            c_counter = 0;
    }

    for (int y = 0; y < m_size ; y++){
        processedmex += replace(mex[y],key_on_mex[y],way);
    }

 
    return processedmex;
}

bool check_supported(string input){
    int i_size = input.size()-1;
    bool supported = true;

    for(int x = 0; x <= i_size; x++){
        // uppercase alphabet is between ascii value 65 an 90, space is at 32
            if ( !((input[x] >= 65 && input[x] <= 90) || input[x] == 32) ){
                supported = false;
                break;
            }
        }
    

    return supported;
}

void use_algo(string key,bool way){
    bool check = true;
    string mex,digest;
    while(check){
        if(way)
            cout << "Inserisci il messaggio che desideri criptare" << endl;
        else
            cout << "Inserisci il messaggio che desideri decriptare" << endl;
        
        getline(cin,mex);
        
        if(check_supported(mex)){
            digest = algorithm(mex,key,way);
            check = false;
        }
        else{
            cout << "SOLO MAIUSCOLE!!!" << endl;
            cin.clear();
            cin.ignore(1000,'\n');
            fflush(stdin);
        }

    }
    cout << "Dopo aver macinato il tutto in questo sofisticato algoritmo il risultato è: " << endl << endl;
    cout << digest << endl;
    cout << "Premi per continuare";
    system("read");
    system("clear");

}

string set_key(){
    bool ok = false;
    string key;
    while(!ok){
        cout << "Inserisci key:";
        cin >> key;
        ok = check_supported(key);
        if(ok){
            system("clear");
            cin.clear();
            cin.ignore(1000,'\n');
            fflush(stdin);
        }
    }
    return key;
}

int menu(){
    string key, mex;
    bool controllo_menu;
    int scelta;
    
    while(true){
        controllo_menu = true;
        while(controllo_menu){
            cout << " Menu " << endl << endl;
        
            cout << "La chiave impostata è: " << key << endl << endl;
            cout << "1) Inserimento chiave " << endl;
            cout << "2) Codifica del messaggio " << endl;
            cout << "3) Decodifica del messaggio " << endl;
            cout << "4) Fine " << endl;

            cin >> scelta;

            if(scelta >= 1 && scelta <= 4 ){
                controllo_menu = false;
                cin.clear();
                cin.ignore(1000,'\n');
                fflush(stdin);
                system("clear");
                break;
            }
            else{
                cin.clear();
                cin.ignore(1000,'\n');
                fflush(stdin);
                system("clear"); 
            }
        }
        
        switch (scelta){
            case 1:
                key = set_key();
            break;

            case 2:
                if(key == ""){
                    cout << "Prima di poter usa questa opzioni inserisci una chiave (opz. 1)" << endl;
                    break;
                }
                use_algo(key,true);        
                break;
            case 3:
                if(key == ""){
                    cout << "Prima di poter usa questa opzioni inserisci una chiave (opz. 1)" << endl;
                    break;
                }
                use_algo(key,false);   
                break;
            case 4:
                return 0;
            break;
        }
    }
}

int main(){
    menu();
}