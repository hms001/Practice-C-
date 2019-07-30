#include <stdlib.h>
#include <iostream>
#include <string>
#include "include_macro.h"
#include "test_optional_param.h"
#include "libUtil.h"
#include <fstream>

using namespace std;

void write_out(string txt,int type,string loginfo);

struct Person{
  std::string name;
  string gender;
  int age;

};

int main(){

	cout << "starts main" << endl;
	std::string text = "Hello";
	std::string text1 = "";
	int var = 2;
	const char * txt = NULL;
	std::string* test = NULL;
	std::string* test1 = &text;
	int* val = NULL;
	string sentence = "This is a sentence.\rAnd another sentence";
	std::ostringstream testnewline1;
	testnewline1 << "Hello World" << std::endl << "Testing new line" << std::endl << "And another line.";
	string convertText = testnewline1.str();

	string sentence2 = "This is a sentence.\nAnd new line.\rAnother line.";
	string sentence3 = "This is a sentence, another sentence, right way, wrong way, correct way";
	string testjson = "{{pi:3.14}}";
	boost::property_tree::ptree parser, child;
	parser.put("id","0");
	child.put("first", "i");
	child.put("second", "love");
	child.put("third", "you");
	parser.put_child("text", child);
	parser.put("type", "test");
	parser.put("begin", 1);
	parser.put("end", 1);
	stringstream ss;
	boost::property_tree::json_parser::write_json(ss, parser);

	ofstream fout;
	int num{12345678};
	Person someone = {"Suzy","Female",22};
	Person someoneElse = {};

	std::string s = "&quot;Music&quot; &amp; &quot;video&quot;";

//	cout << "Before LOG" << endl;
//	LOG(text,3);
//	WRITE(txt,3);

//	test_optional_param param;
//	param.OPTPARAMS("World");
	/*
	if(text1.empty()){
		cout << "text1 is empty" << endl;
	}
	else{
		cout << "text1 is not empty" << endl;
	}
	*/
//	string ver = Utils::indentstring(convertText);
//		cout <<  ver << endl;

	/*
	string result = Utils::ifnull(txt,text.c_str());
	cout << "ifnull() " << result << endl;

	string getResult = Utils::nullstr(txt);
	cout << "nullstr() " << getResult << endl;

	int intResult = Utils::nullnum(val);
	cout << "nullnum() " << intResult << endl;

	string ver = Utils::indentstring_ver2(sentence);
	cout <<  ver << endl;

	string ver1 = Utils::indentstring_ver2(sentence1);
	cout << ver1;

	string ver2 = Utils::indentstring_ver2(sentence2);
	cout << ver2 ;

	string ver3 = Utils::indentstring_ver2(sentence3);
	cout << ver3 << endl;
	*/
//	stringstream stri = Utils::read_file("RF.txt");
//	cout << stri.str();

//	string errmsg = Utils::get_system_message("Message received" , 2);
//	cout << errmsg << endl;
//
//	int confirm = Utils::has_new_line(convertText);
//
//	cout << "new line ? " << confirm << endl;
//
//	string uid = Utils::uuid();
//	cout << "UUID1 : " << uid << endl;
//
//	int checkint = Utils::is_integer("+90");
//	cout << "INTEGER ? " << checkint << endl;
//
//	double checkdouble = Utils::is_decimal_number("+0.8");
//	cout << "DOUBLE ? " << checkdouble << endl;

//	int value = Utils::test("pc_user");

//	cout << "Table number ? " << value << endl;

//	string filename = Utils::scalar2file((char*)&someone,"text.tmp",1);
//	cout << "Filename ? " << filename << endl;
//	Utils::readscalar2file((char*)&someoneElse,(char*)&someone,"test.tmp");
//	cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.gender << endl;

//	string result = Utils::format_abn("65098283044");
//	cout << "ormat_abn ? " << result << endl;
//
//	string result1 = Utils::format_acn("131477480");
//	cout << "format_acn ? " << result1 << endl;
//
//	string result2 = Utils::format_phone("1131477480");
//	cout << "format_phone ? " << result2 << endl;
//
//	string result3 = Utils::format_peak("234.123000");
//	cout << "format_peak ? " << result3 << endl;
//
//	string result4 = Utils::get_date_format_YYYY_MM_DD("2018-09-22");
//	cout << "get_date_format_YYYY_MM_DD ? " << result4 << endl;
//
//	string result5 = Utils::fix_url_encode("Hello hi again");
//	cout << "fix_url_encode ? " << result5 << endl;
//
//	string result6= Utils::days_in_date_month("2020-02-03");
//	cout << "days_in_date_month ? " << result6 << endl;
//	cout << "End of month = " << boost::gregorian::gregorian_calendar::end_of_month_day(2020,02) << endl;

//	string result7 = Utils::format_output_date("2019-02-03","%Y-%m-%d");
//	cout << "format_output_date ? " << result7 << endl;

//	string result8 = Utils::get_ordinal_suffix_day(22);
//	cout << "Date value ? " << result8 << endl;

//	string result9 = Utils::get_mysql_timezone_convert_str("2018-01-31 23:09:43");
//	cout << "Time difference : " << result9 << endl;

//	Utils::financial_quarter fq;
//	fq = Utils::previous_quarter("2020-03-22");
//	cout << "end_date => " << fq.end_date << endl;
//	cout << "text => " << fq.text << endl;
//	cout << "start_date => " << fq.start_date << endl;
//	cout << "short_text => " << fq.short_text<< endl;
//
//	Utils::datetime dt;
//	dt = Utils::date_diff("2018-01-09","2020-03-31");
//	cout << dt.years << endl;
//
//	int total = Utils::get_total_days(dt);
//	cout << "Value : " << total << endl;
//
//	Utils::datetime dt;
//	dt = Utils::timestamp_diff("2018-01-09 09:10:00","2020-03-31 08:12:20");
//	cout << "years => " << dt.years << endl;
//	cout << "months => " << dt.months << endl;
//	cout << "days => " << dt.days << endl;
//	cout << "minutes => " << dt.minutes << endl;
//	cout << "seconds => " << dt.seconds << endl;

//	Utils::financial_quarter fq;
//	fq = Utils::test("2020-03-22");
//	cout << "end_date => " << fq.end_date << endl;
//	cout << "text => " << fq.text << endl;
//	cout << "start_date => " << fq.start_date << endl;
//	cout << "short_text => " << fq.short_text<< endl;

	Utils::test();

//	string url = Utils::UrlEncode("hello hi again here");
//	cout << "url value ? " << url << endl;
//
//	string decoding = Utils::UrlDecode(url);
//	cout << "url value ? " << decoding << endl;


//	fout.open("./tmp/test.tmp",ios::binary);
//	if(fout.is_open()){
//	    fout.write(reinterpret_cast<char *>(&sentence3),sizeof(sentence3));
//	    fout.close();
//	}
//	else{

//	}
	/*
	bool binary = 0 ;
	string filename = "";
	boost::filesystem::path tempfile;
	string fullname;
	string complete_file_name;
	if(filename.empty()){
	    try{
	  boost::filesystem::create_directory("./tmp");
	    }
	    catch(boost::filesystem::filesystem_error &e)
	    {
	      std::cerr << e.what() << endl;
	    }
	    boost::filesystem::path tempfile = boost::filesystem::unique_path();
	    complete_file_name = tempfile.native() + ".tmp";
	    fullname = "./tmp/" + complete_file_name;

	}
	else{
	    fullname = filename;
	    complete_file_name = filename;
	}

	if(binary ==1 ){
	    fout.open(fullname,ios::binary);
	    if(fout.is_open()){
	  fout.write(reinterpret_cast<char *>(&sentence3),sizeof(sentence3));
	  fout.close();
	    }
	}
	else{
	    fout.open(fullname);
	    if(fout.is_open()){
	  fout.write(reinterpret_cast<char *>(&sentence3),sizeof(sentence3));
	  fout.close();
	    }
	}
	*/
//	sentence3 = "";
//	   fstream fread;
//	    string line;
//	    fread.open(temp,ios::in);
//	    if(fread.is_open()){
//		fread.read(reinterpret_cast<char *>(&sentence3),sizeof(sentence3));
//		fread.close();
//	    }
//	    cout << sentence3 << endl;
//	    cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.gender << endl;
	return EXIT_SUCCESS;
}



void write_out(string txt,int type, string loginfo)
{
//	string file_name,string function, int lineno
//	std::cout << txt << " " << type << " " << file_name << " " <<  function << " " <<  lineno<< endl;
	std::cout << txt << " " << type << " " << loginfo << endl;
}
