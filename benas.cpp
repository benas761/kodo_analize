void naujasFailas(list <mokinys> m, int psk, int k){
    string name;
    char vard[6] = {'V', 'a', 'r', 'd', 'a', 's'}, pav[7] = {'P', 'a', 'v', 'a', 'r', 'd', 'e'};
    int fx=1000*pow(10, k);
    name = to_string(fx) + ".txt";
    ofstream fr1(name.c_str());
    fr1 << left << setw(20) << "Pavarde" << setw(20) << "Vardas";
    for(int i=0; i<psk; i++)
    fr1 << "ND" << setw(8) << 1+i;
    fr1 << setw(10) << "Egz." << endl;
    m.push_back(mokinys());
    list <mokinys> :: iterator it = m.begin();
    for(int i=0; i<fx; i++){
        for(int j=0; j<6; j++){
            it->n = psk;
            it->pav.push_back(pav[j]);
            it->vard.push_back(vard[j]);
        }
        it->pav.push_back(pav[6]);
        m.push_back(mokinys());
        it++;
    }
    it--;
    it = m.begin();
    for(int j=0; j<fx; j++){                      //pazymiu generavimas
        for(int i=0; i<it->n; i++){
            int z=rand()%10+1;
            it->nd.push_back(z);
        }
        it->e=rand()%10+1;
        it++;
    }
    it = m.begin();
    for(int i=0; i<fx; i++){                    //Rasymas i faila
        fr1 << it->pav << setw(13) << 1+i << it->vard << setw(14) << i+1;
        for(list <double> :: iterator it2 = it->nd.begin(); it2!=it->nd.end(); it2++)
            fr1 << setw(10) << *it2;
        fr1 << setw(10) << it->e << endl;
        it++;
    }
    fr1.close();
}

void nuskaitymas(list <mokinys> &m, int &C, int k){
    m.push_back(mokinys());
    list <mokinys> :: iterator it = m.begin();
    C=0;
    char c; int words = -3; bool space = true; int ND;
    int fx=1000*pow(10, k);
    string name = to_string(fx) + ".txt", vard, pav;
    ifstream fd(name.c_str());
    while(fd.get(c) and c!='\n'){           //skaiciuoja kiek nd
        if(std::isspace(c)){
            space=true;
        }
        else if(space){
            words++;
            space=false;
        }
    }
    for(int j=0; j<fx; j++){                       //nuskaito duomenis is failo
        m.push_back(mokinys());
        it->n=words;
        fd >> pav;
        char P[pav.length()];
        strcpy(P, pav.c_str());
        for(int i=0; i<pav.length(); i++)
            it->pav.push_back(P[i]);
        fd >> vard;
        char H[vard.length()];
        strcpy(H, vard.c_str());
        for(int i=0; i<vard.length(); i++)
            it->vard.push_back(H[i]);
        for(int i=0; i<words; i++){
            fd >> ND;
            it->nd.push_back(ND);
        }
        fd >> it->e;
        C++;
        it++;
    }
    m.pop_back();
    C--;
}