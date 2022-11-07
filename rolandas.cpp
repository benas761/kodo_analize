void CreateInput(int student_number, int homework_number) { // funkcija skaičių generavimui
	std::random_device random_device;
	std::mt19937 mt0(random_device());
	std::uniform_int_distribution<int> grades(1, 10);  //generuojami skaičiai nuo 1 iki 10
	std::ofstream file_read("generated.txt");
	file_read << setw(33) << std::left << "Vardas" << setw(30) << std::left << "Pavarde";
	for(int j = 0; j < homework_number; j++) file_read << setw(3) << std::right << j+1 << "nd";
	file_read << setw(5) << "egz." << endl;
	for(int i=1; i<=student_number; i++) {
		file_read << "Vardas" << setw(27) << std::left << i;
		file_read << "Pavarde" << setw(26) << std::left << i;
		for(int j = 0; j < homework_number+1; j++) file_read << setw(5) << grades(mt0);
		file_read << endl;
	}
	file_read.close();
}

void FileInput(vector<student> &x, string input) {
	string _string; stud temporary;
	std::ifstream file(input);
	getline(file, _string); // Praleidzia pirma linija
	while(getline(file, _string)) {
		x.push_back(temporary);
		std::istringstream string_stream(_string);
		string_stream >> x.back().name >> x.back().last_name;
		int integer;
	    while(string_stream >> integer) if(integer <= 10 || integer > 0) x.back().homework.push_back(integer);
	    if(x.back().homework.size() > 1) {
	    	x.back().exam = x.back().homework.back();
	    	x.back().homework.pop_back();
		}
		else if(x.back().homework.size() == 0) {
			x.back().exam = x.back().homework.back();
			x.back().homework.back() = 0;
		}
		else {
			x.back().exam = 0;
			x.back().homework.back() = 0;
		}
	}
	file.close();
}

void CmdInput(vector<stud> &x) {
	using std::cin;
	string _string; stud temporary;
    getline(cin, _string);  // Ignoruoja pasilikusi \n (getline, nes ignore tarpus priskaiciuoja)
	cout << "Iveskite mokiniu vardus, pavardes ir pazymius (egzamino pazymys paskutinis, vienas mokinys - viena eilute)\nNorint baigti iveskite tuscia eilute.\n";
	while(getline(cin, _string)) {
		if(_string == "") break;
		x.push_back(temporary);
		std::istringstream string_stream(_string);
		string_stream >> x.back().name >> x.back().lastname;
		int integer;
	    while(string_stream >> in) if(integer <= 10 || integer > 0) x.back().homework.push_back(integer);
	    if(x.back().homework.size() > 1) {
	    	x.back().exam = x.back().homework.back();
	    	x.back().homework.pop_back();
		}
		else if(x.back().homework.size() == 1) {
			x.back().exam = x.back().homework.back();
			x.back().homework.back() = 0;
		}
		else {
			x.back().exam = 0;
			x.back().homework.push_back(0);
		}
	}
}