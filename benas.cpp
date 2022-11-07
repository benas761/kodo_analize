void NewFile(list <mokinys> student, int homework_count, int student_count_thousands){
    string file_name;
    char name_string[6] = {'V', 'a', 'r', 'd', 'a', 's'};
    char last_name_str[7] = {'P', 'a', 'v', 'a', 'r', 'd', 'e'};
    int student_count=1000*pow(10, student_count_thousands);
    file_name = to_string(homework_count) + ".txt";
    ofstream fr1(file_name.c_str());
    fr1 << left << setw(20) << "Pavarde" << setw(20) << "Vardas";
    for(int i=0; i<homework_count; i++)
        fr1 << "ND" << setw(8) << 1+i;
    fr1 << setw(10) << "Egz." << endl;
    students.push_back(mokinys());
    list <mokinys> :: iterator student_iterator = students.begin();
    for(int i=0; i<student_count; i++){
        for(int j=0; j<6; j++){
            student_iterator->n = homework_count;
            student_iterator->pav.push_back(last_name[j]);
            student_iterator->vard.push_back(vard[j]);
        }
        student_iterator->pav.push_back(last_name[6]);
        students.push_back(mokinys());
        student_iterator++;
    }
    student_iterator--;
    student_iterator = students.begin();
    for(int j=0; j<student_count; j++){                      //pazymiu generavimas
        for(int i=0; i<student_iterator->n; i++){
            int z=rand()%10+1;
            student_iterator->nd.push_back(z);
        }
        student_iterator->e=rand()%10+1;
        student_iterator++;
    }
    student_iterator = students.begin();
    for(int i=0; i<student_count; i++){                    //Rasymas i faila
        fr1 << it->pav << setw(13) << 1+i << student_iterator->vard << setw(14) << i+1;
        for(list <double> :: iterator homework_iterator = student_iterator->nd.begin(); 
            homework_iterator!=it->nd.end(); homework_iterator++)
            fr1 << setw(10) << *homework_iterator;
        fr1 << setw(10) << student_iterator->e << endl;
        student_iterator++;
    }
    fr1.close();
}

void Reading(list <mokinys> &students, int &student_count, int student_count_thousands){
    students.push_back(mokinys());
    list <mokinys> :: iterator student_iterator = students.begin();
    student_count=0;
    char character; int words = -3; bool is_space = true; int homework_grade;
    int student_count=1000*pow(10, student_count_thousands);
    string file_name = to_string(student_count) + ".txt", name, last_name;
    ifstream fd(file_name.c_str());
    while(fd.get(character) and character!='\n'){           //skaiciuoja kiek nd
        if(std::isspace(character)){
            is_space=true;
        }
        else if(space){
            words++;
            is_space=false;
        }
    }
    for(int j=0; j<student_count; j++){                       //nuskaito duomenis is failo
        students.push_back(mokinys());
        student_iterator->n=words;
        fd >> last_name;
        char last_name_chars[last_name.length()];
        strcpy(last_name_chars, last_name.c_str());
        for(int i=0; i<last_name.length(); i++)
            student_iterator->pav.push_back(last_name_chars[i]);
        fd >> name;
        char name_chars[name.length()];
        strcpy(name_chars, name.c_str());
        for(int i=0; i<vard.length(); i++)
            student_iterator->vard.push_back(name_chars[i]);
        for(int i=0; i<words; i++){
            fd >> homework_grade;
            student_iterator->nd.push_back(homework_grade);
        }
        fd >> it->e;
        student_count++;
        student_iterator++;
    }
    students.pop_back();
    student_count--;
}