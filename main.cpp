#include "main.h"
#include "processData.h"

using namespace std;
void usage();


int main(int argc, char** argv) {
	ifstream inFile;
	ofstream outFile;
    
	if (argc != 3){
        usage();
        return EXIT_FAILURE;
    }
	
	inFile.open(argv[1]);
	if (!inFile) {
        cout << "Unable to open file " << argv[1];
        return EXIT_FAILURE; // terminate with error
    }
	
    outFile.open(argv[2]);	
	if (!outFile) {
        cout << "Unable to open file " << argv[2];
        return EXIT_FAILURE; // terminate with error
    }
    
    ProcessData * data = new ProcessData();
	
    string line;
    while (getline(inFile, line)) { 
    	outFile << data->process(line) << endl;
    }
    inFile.close();
    outFile.close();
    delete data;

	return EXIT_SUCCESS;
	/*ProcessData *data = new ProcessData();
	string line1 = "SD 1000";
	string line2 = "SL 100";
	string line3 = "CD";
	string line4 = "INS EUR USD 1101 1.102090 1.102150";
	string line5 = "INS EUR USD 1103 1.01284 1.01235";
	string line6 = "INS EUR USD 1107 1.101950 1.101980";
	string line7 = "INS EUR USD 1107 1 1";
	string line8 = "OS EUR USD 1101 0.33 1123456";
	string line9 = "INS USD VND 10009 1.23132 1.23123";
	string line10 = "INS USD VND 10010 1.23132 1.23123";
	string line11 = "INS USD VND 10011 1.23132 1.23123";
	string line12 = "DEL USD VND 10003 10012";
	data->process(line1);
	data->process(line2);
	data->process(line3);
	data->process(line4);
	data->process(line5);
	data->process(line6);
	data->process(line7);
	data->process(line8);
	data->process(line9);
	data->process(line10);
	data->process(line11);
	data->process(line12);
//	string line1 = "OS EUR USD 1101 0.33 1123456";
	//string line2 = "SL 100";
	//data->process(line1);
	//data->process(line2);
	//data->process(line2);
	////data->process(line1);
	data->in();*/

}
void usage() {
	cout << "Usage: main <input file> <output file>" << endl;
}