/*
 * libUtil.h
 *
 *  Created on: 14 May 2019
 *      Author: hmsandi
 */

#ifndef LIBUTIL_H_
#define LIBUTIL_H_

#include <string>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
/** provides overloaded operator to write objects of type boost::uuids::uuid to an output stream */
#include <boost/uuid/uuid_io.hpp>
#include <nlohmann/json.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/lexical_cast.hpp>
#include "boost/format.hpp"
#include <boost/locale.hpp>
#include <locale>
#include <iomanip>
#include <map>
#include <boost/assign.hpp>

//#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdbool.h>

#include <boost/filesystem.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/local_time_adjustor.hpp>
#include <boost/date_time/c_local_time_adjustor.hpp>

//#include <boost/date_time/local_time/local_time.hpp>
#include <cmath>
//#include <cstdio>
//#include <boost/locale/utf8_codecvt.hpp>
//#include <codecvt>
//#include <assert.h>
//#include "utf8.h"
//#include <boost/regex/icu.hpp>


using boost::property_tree::ptree;
using boost::property_tree::read_json;

using namespace std;

namespace Utils
{
  static string ifnull(const char* firstvar,const char* secvar)
  {
    if(!firstvar)
      {
	return secvar;
      }
    return firstvar;
  }

  static string nullstr(const char* var)
  {
    if(!var)
      {
	 cout << "empty string" << endl;
	 return std::string();
      }
    //return empty string
    cout << "var string" << endl;
    return var;
  }

  static int nullnum(int *i)
  {
    if(!i)
      {
	cout << "value return" << endl;
	return 0;
      }
    cout << "not null return" << endl;
    return *i;
  }

  static string indentstring(string var)
  {
    string combine;
    string text;
    string pad="     ";
    std::vector<std::string> results;

//    boost::regex newline("((?s)+$)");
    boost::regex carriagereturn("(.|\r\n)*");

    if(boost::regex_match(var, carriagereturn)){
      combine="\n";
      cout << "found new line" << endl;
    }
//    else if(boost::regex_match(var, carriagereturn)){
//	combine="\r";
//	cout << "combine 3" << endl;
//    }
    else{
    	cout << "no match " << endl;
    	return pad + var;
    }
    boost::split(results, var, boost::is_any_of(combine));
    for(string line : results){
    	text += pad + line + combine;
    }

    return text;
  }

  static string indentstring_ver2(std::string input){

    std::size_t index;
    string cr;
    string text;
    string pad;
    string r;
    std::vector<std::string> results;
    bool check = 1;
    if(pad.empty()){
	pad="     ";
    }

    if(((index = input.find("\n")) != std::string::npos) && ((index = input.find("\r")) != std::string::npos)){
    	cr = "\n\r";
    	cout << "add new line and carriage return" << endl;
    }
    else if((index = input.find("\n")) != std::string::npos){
    	cr = "\n";
    	cout << "add new line" << endl;
    }
    else if((index = input.find("\r")) != std::string::npos){
	cr = "\r";
	cout << "add new carriage return" << endl;
    }
    else{
	cr = pad + input;
	return cr;
    }

    boost::split(results, input, boost::is_any_of(cr));

    for(string line : results){

    	text += pad + line + cr;
//    	text.append(cr);
    }

    return text;
  }

  static std::stringstream read_file(const std::string& fileName){
//    const std::string& fileName = "RF.txt";
    std::string content;
    std::string line;
    string cr;
    std::string::size_type index;
    std::ifstream ifs(fileName, std::ifstream::in);
    if (ifs.is_open())
    {
	while (!ifs.eof())
	{
	    getline(ifs, line);
	    content.append(line);
	}
	ifs.close();
    }
    else
    {
	//std::cout << "File not found." << std::endl;
	std::stringstream result("");
	return result;
    }

    return std::stringstream(content);
  }

  static std::string get_system_message(std::string message, int level)
  {
    std::string msg;

    if(level == 1 ) {
	msg = "System Error Generated : " + message;
    }

    if(level == 2) {
	msg = "System Information Generated : " + message;
    }

    if(level == 3) {
    	msg = "System Warning Generated : " + message;
    }

    return msg;

  }


  static int has_new_line(std::string text)
  {
//    stringstream check = stringstream(text);
//    std::string line;
//    int count =0;
    if(text.empty()){
	cout << "empty string" << endl;
	return 0;
    }

//    else{

     boost::regex findnewline("(.|\r\n)*");
     if(boost::regex_match(text, findnewline)){
	   cout << "found new line" << endl;
	   return 1;
      }
//          while(getline(check,line)){
//	    cout << line << " : new line" << endl;
//	    ++count;
//
//          }
//          if(count >= 1){
//    	  cout << "has new line" << endl;
//    	  return 1;
//          }
//    }
    return 0;
  }

  static double is_decimal_number(string text)
  {

    boost::regex expression("(-?[0-9]+\\.[0-9]+)");

    if(boost::regex_match(text, expression)){
      cout << "double" << endl;
      return 1;
    }
    else{
	cout << "not double" << endl;
	return 0;
    }
    return 0;
  }


  static int is_integer(string text)
    {

      boost::regex expression("(-?[0-9]+)");

      if(boost::regex_match(text, expression)){
      	  cout << "integer" << endl;
      	  return 1;
      }
      else{
	  cout << "not integer" << endl;
	  return 0;
      }
      return 0;
    }

  static string uuid()
  {
    boost::uuids::uuid uuids = boost::uuids::random_generator()();
    string uuid = boost::uuids::to_string(uuids);

    return uuid;
  }

  static vector<std::string> get_all_month_names()
  {
    std::vector<std::string> months = {"January",
					"February",
					"March",
					"April",
					"May",
					"June",
					"July",
					"August",
					"September",
					"October",
					"November",
					"December"};

     return months;

  }

  static vector<std::string> get_all_month_short_names(){

    std::vector<std::string> months;
    std::vector<std::string> collections = get_all_month_names();
    for(string s: collections){
      string value = s.substr(0,3);
      months.push_back(value);
    }
    return months;

  }

  static vector<std::string> get_array_from_str_by_delimiter(std::string text, std::string delimiter){

      std::vector<std::string> results;
      if(text.empty()){
	  return {};
      }
      boost::split(results, text, boost::is_any_of(delimiter));

      return results;

  }

  static int is_json(std::string text)
  {
    stringstream inputStream(text);
        ptree value;
        bool check = 1;

        try{
    	boost::property_tree::read_json(inputStream,value);
	    if(check){
		return 1;
	    }
        }
        catch(const boost::property_tree::json_parser::json_parser_error& e){

            return 0;
        }

        return 0;

  }

  static string format_currency_general(string value, int number_of_digits = 0)
  {
    try{
        std::ostringstream convert;
        std::ostringstream formatted;
        convert << std::setprecision(number_of_digits) << std::fixed ;
        convert <<  stod(value);
	formatted << boost::format("%1%%2%") %"$" %convert.str();
	return formatted.str();
    }
    catch(const std::invalid_argument& x){
	return "0";
    }
  }

  static string format_number(string value, int number_of_digit = 0)
  {
    try{
        std::ostringstream formatted;
        std::ostringstream converted;

        formatted.imbue(std::locale("en_US.UTF-8"));
        formatted << fixed << setprecision(number_of_digit);
        formatted << stod(value);
        converted << boost::format("%1%%2%") %"$" %formatted.str();
        return converted.str();
    }
    catch(const std::invalid_argument& x){
	return "0";
    }
  }

  struct space_out : numpunct<char> {
     /* use space as separator */
     char do_thousands_sep() const { return ' '; }

     /* digits are grouped by 3 digits each */
     string do_grouping() const { return "\3"; }
  };


  static string format_currency(string value, int number_of_digit = 0)
  {
    try{
        std::ostringstream formatted;
        std::ostringstream converted;

        formatted.imbue(std::locale(formatted.getloc(), new space_out));
        formatted << fixed << setprecision(number_of_digit);
        formatted << stod(value);
        converted << boost::format("%1%%2%") %"$" %formatted.str();
        return converted.str();
    }
    catch(const std::invalid_argument& x){
	return "0";
    }
  }

  static bool invalid_email_address(std::string email)
  {

    int pass = 0;
    std::vector<std::string> email_addresses;
    boost::split(email_addresses, email, boost::is_any_of(", "),boost::token_compress_on);

    for(string validate_email : email_addresses){

	boost::regex email_pattern("^[a-zA-Z0-9][a-zA-Z0-9_.]+@[a-zA-Z0-9_]+.[a-zA-Z0-9_.]+$");

	if(boost::regex_match(validate_email, email_pattern)){
	    pass++;
	}

    }

    if(pass == email_addresses.size()){
	return 1;
    }
    else{
	return 0;
    }

    return 0;
  }

  map<string,int> tn_numbers = boost::assign::map_list_of("pc_invoice_issue",1)
							  ("pc_publication_instance_output",2)
							  ("pc_tender_file",3)
							  ("pc_user",4)
							  ("pc_files",5)
							  ("pc_correspondance_history",6);

  map<int, string> tn_names = {{1,"pc_invoice_issue"},
			       {2,"pc_publication_instance_output"},
			       {3,"pc_tender_file"},
			       {4,"pc_user"},
			       {5,"pc_files"},
			       {6,"pc_correspondance_history"}};

  static int get_tn_table_number(string table_name)
  {
	map<string,int>::iterator table;
	table = tn_numbers.find(table_name);
        if(table == tn_numbers.end()){
            return -1;
        }

        return table->second;
  }

  static string get_tn_table_name(int table_number)
  {
	map<int,string>::iterator number;
	number = tn_names.find(table_number);

        if(number == tn_names.end()){
            return "";
        }

        return number->second;
  }

  static std::string scalar2file(const char *content, std::string filename, bool binary){


//    try{
//    	    boost::filesystem::create_directory("./tmp");
//    }
//    catch(boost::filesystem::filesystem_error &e)
//    {
//	    std::cerr << e.what() << endl;
//     }
      ofstream fout;
//    fout.open(filename,ios::out | ios::app | ios::binary);
//    if(fout.is_open()){
//	fout.write(reinterpret_cast<char *>(&text),sizeof(&text));
//	fout.close();
//    }
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
		fout.write(reinterpret_cast<char *>(&content),sizeof(content));
		fout.close();
	    }
	}
	else{
	    fout.open(fullname);
	    if(fout.is_open()){
		fout.write(reinterpret_cast<char *>(&content),sizeof(content));
		fout.close();
	    }
	}

	return complete_file_name;

  }

  static void readscalar2file(const char * text, const char * origin, std::string filename){
    fstream fread;
    string line;
    fread.open(filename,ios::in);
    if(fread.is_open()){
//	fread.read(reinterpret_cast<char *>(&text),sizeof(text));

	while ( std::getline (fread,line) )
	{
	    cout << line << endl;
	}
//	fread >> reinterpret_cast<char *>(&text);
	fread.close();
    }
  }


  static string fix_utf8_special_characters(string text)
  {
    if(text.empty()){
	std::runtime_error("no string passed to library _fix_utf8_special_characters");
	return "";
    }

    string subs[] = {
    		"& #34;", "&quot;",
    		"& #39;", "&apos;",
    		"& #38;", "&amp;",
    		"& #60;", "&lt;",
    		"& #62;", "&gt;",
    		"&34;", "&39;",
    		"&38;", "&60;",
    		"&62;"
    	};

    string reps[] = {
    		"\"", "\"",
    		"'", "'",
    		"&", "&",
    		"<", "<",
    		">", ">",
    		"\"", "'",
    		"&", "<",
    		">"
    	};

    	size_t found;
    	for(int j = 0; j < 15; j++) {
    		do {
    			found = text.find(subs[j]);
    	  		if (found != string::npos)
    		    		text.replace (found,subs[j].length(),reps[j]);
        		} while (found != string::npos);
      	}

    return text;
  }

  static std::string format_abn(string number)
  {
    try{
	std::ostringstream formatted;
	std::ostringstream converted;
	cout << "number.length() = " << number.length() << endl;
	if(number.length() == 11){
	  formatted.imbue(std::locale(formatted.getloc(), new space_out));
	      formatted << stol(number);
	  converted << boost::format("%1%") %formatted.str();
	  return converted.str();
	}
	else
	  return "";
    }
    catch(const std::out_of_range& e){
	return "";
    }
    catch(const std::invalid_argument& x){
	return "";
    }
  }

  static std::string format_acn(std::string number)
  {
      try{
	std::ostringstream formatted;
	std::ostringstream converted;

	if(number.length() == 9){
	  formatted.imbue(std::locale(formatted.getloc(), new space_out));
	  formatted << stoi(number);
	  converted << boost::format("%1%") %formatted.str();
	  return converted.str();
	}
	else
	  return "";
      }
      catch(const std::out_of_range& e){
	return "";
      }
      catch(const std::invalid_argument& x){
	return "";
      }
  }


  static string format_phone(std::string number)
  {
    try{
        std::ostringstream formatted;
        boost::regex isnumber("^-?\\d+");
        if(boost::regex_match(number,isnumber)){
	  if(number.length() == 10){

	    formatted << boost::format("%1% %2% %3%") %number.substr(0,4) %number.substr(4,3) %number.substr(7,3);
	    return formatted.str();
	  }
        }
        return "";
    }
    catch(const boost::regex_error& e){
	return "";
    }

  }

  static string format_peak(string number)
  {
    try{
        std::ostringstream formatted;
        string result;
        boost::regex isnumber("(^-?\\d*\\.\\d+?)0+$");
        if(boost::regex_match(number,isnumber)){
            result = boost::regex_replace(number,isnumber,"$1");
            return result;
        }
        return "";
     }
     catch(const boost::regex_error& e){
   	return "";
       }
  }

  static string get_date_format_YYYY_MM_DD(string number)
  {
	try{
		std::vector<std::string> date_split;
		std::ostringstream date_format;
		boost::split(date_split, number, boost::is_any_of("-"));
		string year = date_split[0];
		string month = date_split[1];
		string day = date_split[2];
		date_format << boost::format("%1%-%2%-%3%") %year %month %day;
		return date_format.str();
	}
    catch(const boost::io::bad_format_string& e){
    	cout << e.what() << endl;
    }

    return "";

  }

  /*Reference: http://www.voidcn.com/article/p-yqopsbes-od.html*/
  static unsigned char ToHex(unsigned char x)
  {
      return  x > 9 ? x + 55 : x + 48;
  }

  static unsigned char FromHex(unsigned char x)
  {
      unsigned char y;
      if (x >= 'A' && x <= 'Z') y = x - 'A' + 10;
      else if (x >= 'a' && x <= 'z') y = x - 'a' + 10;
      else if (x >= '0' && x <= '9') y = x - '0';
      else assert(0);
      return y;
  }

  static std::string UrlEncode(const std::string& str)
  {
      std::string strTemp = "";
      size_t length = str.length();
      for (size_t i = 0; i < length; i++)
      {
          if (isalnum((unsigned char)str[i]) ||
              (str[i] == '-') ||
              (str[i] == '_') ||
              (str[i] == '.') ||
              (str[i] == '~'))
              strTemp += str[i];
          else if (str[i] == ' ')
              strTemp += "+";
          else
          {
              strTemp += '%';
              strTemp += ToHex((unsigned char)str[i] >> 4);
              strTemp += ToHex((unsigned char)str[i] % 16);
          }
      }
      return strTemp;
  }

  static std::string UrlDecode(const std::string& str)
  {
      std::string strTemp = "";
      size_t length = str.length();
      for (size_t i = 0; i < length; i++)
      {
          if (str[i] == '+') strTemp += ' ';
          else if (str[i] == '%')
          {
              assert(i + 2 < length);
              unsigned char high = FromHex((unsigned char)str[++i]);
              unsigned char low = FromHex((unsigned char)str[++i]);
              strTemp += high*16 + low;
          }
          else strTemp += str[i];
      }
      return strTemp;
  }

  static string fix_url_encode(const std::string& url)
  {
	    try{
	    	if(url.empty()){
	    		throw std::runtime_error("no string passed to library fix_url_encode");
	    		return "";
	    	}
	    	std::ostringstream format;
	    	std::string urlencoded = UrlEncode(url);
	    	boost::regex newtext("\\+");
	    	string str = "%20";
	    	format << boost::regex_replace(urlencoded,newtext,str);
	    	return format.str();
	    }
	    catch(const boost::regex_error& e){
	    	cout << e.what() << endl;
	    	return "";
	    }
  }

  static void last_day_of_month()
  {
		boost::gregorian::greg_year year(1400);
		boost::gregorian::greg_month month(1);
	    try{
	    	year = boost::gregorian::greg_year(2019);
	    	month = boost::gregorian::greg_month(2);

	    }
	    catch(boost::gregorian::bad_year& by) {
	          std::cout << "Invalid Year Entered: " << by.what() << '\n'
	            << "Using minimum values for month and year." << std::endl;
	        }
		catch(boost::gregorian::bad_month& bm) {
	          std::cout << "Invalid Month Entered" << bm.what() << '\n'
	            << "Using minimum value for month. " << std::endl;
	     }
		boost::gregorian::date start_of_next_year(year+1, boost::gregorian::Jan, 1);
		boost::gregorian::date d(year, month, 1);

		while (d < start_of_next_year){
		      std::cout << to_simple_string(d.end_of_month()) << std::endl;
		      d += boost::gregorian::months(1);
		 }
  }

  static string days_in_date_month(std::string inputDate)
  {
	  try{
		  std::vector<std::string> date_split;
		  boost::gregorian::date d(boost::gregorian::from_simple_string(inputDate));

		  string numofdays = to_simple_string(d.end_of_month());
		  boost::split(date_split, numofdays, boost::is_any_of("-"));
		  return date_split[2];

	  }
	 catch(boost::gregorian::bad_year& by) {
		  std::cout << "Invalid Year Entered: " << by.what() << '\n'
			<< "Using minimum values for month and year." << std::endl;
		  return "";
	 }
	 catch(boost::gregorian::bad_month& bm) {
		  std::cout << "Invalid Month Entered" << bm.what() << '\n'
			<< "Using minimum value for month. " << std::endl;
		  return "";
	 }
	 catch(boost::gregorian::bad_day_of_month& bdm) {
		  std::cout << "Invalid day Entered... " << bdm.what() << '\n'
						<< "Using minimum value for day. " << std::endl;
		  return "";
	 }

  }

  static string format_output_date(const std::string& input_date_str, std::string output_format_date)
  {
	  try{
		  std::ostringstream outputformat;
		  boost::regex input_date("^\\d{4}-\\d\\d-\\d\\d$");
		  if(boost::regex_match(input_date_str,input_date)){
			  boost::gregorian::date d(boost::gregorian::from_simple_string(input_date_str));
			  boost::gregorian::date_facet* facet(new boost::gregorian::date_facet(output_format_date.c_str()));
			  outputformat.imbue(std::locale(outputformat.getloc(),facet));
			  outputformat << d;
			  return outputformat.str();

		  }
		  else{
			  cout << "ERROR DATE FORMAT: input_date_str value is not correct format %Y-%m-%d." << endl;
			  return "";
		  }

	  }
	 catch(boost::gregorian::bad_year& by) {
		  std::cout << "Invalid Year Entered: " << by.what() << '\n'
			<< "Using minimum values for month and year." << std::endl;
		  return "";
	 }
	 catch(boost::gregorian::bad_month& bm) {
		  std::cout << "Invalid Month Entered" << bm.what() << '\n'
			<< "Using minimum value for month. " << std::endl;
		  return "";
	 }
	 catch(boost::gregorian::bad_day_of_month& bdm) {
		  std::cout << "Invalid day Entered... " << bdm.what() << '\n'
						<< "Using minimum value for day. " << std::endl;
		  return "";
	 }
	 catch(boost::bad_lexical_cast& lex){
		 std::cout << "Wrong Format Entered... " << lex.what() << std::endl;
		 return "";
	 }

  }

  static std::string get_ordinal_suffix_day(int input_day)
  {
  	  if(input_day >= 1 && input_day <= 31 ){
  		  static const char suffixes [][3] = {"th", "st", "nd", "rd"};
		  int ordinal = input_day;
		  if (ordinal / 10 == 1)
		  {
			  ordinal = 0;
		  }

		  ordinal = ordinal % 10;
		  if (ordinal > 3)
		  {
			  ordinal = 0;
		  }

		  return suffixes[ordinal];
  	  }
  	  else{
  		  return "";
  	  }
  }

	static boost::gregorian::date_duration getDateDuration(std::string date1, std::string date2){

		//check from and end input
		if( date1.empty() or date2.empty() ){
			throw "both days must be defined in routine days_diff";
		}

		boost::gregorian::date_duration duration(0);
		//both date are same
		if(date1.compare(date2) == 0){
			duration;
		}

		boost::gregorian::date dateObj1(boost::gregorian::from_simple_string(date1));
		boost::gregorian::date dateObj2(boost::gregorian::from_simple_string(date2));
		boost::gregorian::date start = dateObj1 < dateObj2 ? dateObj1 : dateObj2;
		boost::gregorian::date end = dateObj1 < dateObj2 ? dateObj2 : dateObj1;

		// Get the Duration between 2 Dates
		duration = dateObj2 - dateObj1;
		return duration;
	}

	static string get_mysql_timezone_convert_str(string input_date)
	{
		try
		{
			  typedef boost::date_time::c_local_adjustor<boost::posix_time::ptime> local_adj;
			  boost::posix_time::ptime UTCtime(boost::posix_time::time_from_string(input_date));
			  boost::posix_time::ptime convert_to_local = local_adj::utc_to_local(UTCtime);
			  boost::posix_time::time_duration durations = convert_to_local - UTCtime;
			  string time_difference = boost::posix_time::to_simple_string(durations);
			  string to_tz = time_difference.substr(0,5);
			  string str_fmt = "CONVERT_TZ(\'" + input_date + "\',\'+00:00\',\'+" + to_tz + "\')";

			  return str_fmt;
		}
		catch(boost::gregorian::bad_year& by) {
			  std::cout << "Invalid Year Entered: " << by.what() << '\n'
				<< "Using minimum values for month and year." << std::endl;
			  return "";
		 }
		 catch(boost::gregorian::bad_month& bm) {
			  std::cout << "Invalid Month Entered" << bm.what() << '\n'
				<< "Using minimum value for month. " << std::endl;
			  return "";
		 }
		 catch(boost::gregorian::bad_day_of_month& bdm) {
			  std::cout << "Invalid day Entered... " << bdm.what() << '\n'
							<< "Using minimum value for day. " << std::endl;
			  return "";
		 }
		 catch(boost::bad_lexical_cast& lex){
			 std::cout << "Wrong Format Entered... " << lex.what() << std::endl;
			 return "";
		 }

	}

	struct financial_quarter{
		string start_date;
		string end_date;
		string text;
		string short_text;
	};

	static financial_quarter previous_quarter(string input_date)
	{
		  try{

			  if(input_date.empty()){
				  std::runtime_error("date time not passed to cms::libutil::previous_quarter");
			  }

			  boost::gregorian::date initial_day(boost::gregorian::from_simple_string(input_date));
			  //set the first day of month
			  boost::gregorian::date set_day(initial_day.year(),initial_day.month(),1);
			  boost::gregorian::date_duration substract_day(1);
			  boost::gregorian::date minus_1day= set_day - substract_day;
			  //get month as number
			  boost::gregorian::greg_month month_number = minus_1day.month();
			  boost::gregorian::months month_duration(month_number.as_number()%3);
			  boost::gregorian::date end_date = minus_1day - month_duration;

			  boost::gregorian::date initial_start_date(end_date);
			  boost::gregorian::date set_start_day(initial_start_date.year(),initial_start_date.month(),1);
			  boost::gregorian::months substract_month(2);
			  boost::gregorian::date start_date = set_start_day - substract_month;

			  financial_quarter f_quarter;
			  f_quarter.start_date = boost::gregorian::to_iso_extended_string(start_date);
			  f_quarter.end_date = boost::gregorian::to_iso_extended_string(end_date);
			  f_quarter.short_text = format_output_date(f_quarter.start_date,"%b") + "-" + format_output_date(f_quarter.end_date,"%b%Y");
			  f_quarter.text = format_output_date(f_quarter.start_date,"%B%e, %Y") + " to " + format_output_date(f_quarter.end_date,"%B %e, %Y");

			  return f_quarter;

		  }
		 catch(boost::gregorian::bad_year& by) {
			  std::cout << "Invalid Year Entered: " << by.what() << '\n'
				<< "Using minimum values for month and year." << std::endl;

		 }
		 catch(boost::gregorian::bad_month& bm) {
			  std::cout << "Invalid Month Entered" << bm.what() << '\n'
				<< "Using minimum value for month. " << std::endl;

		 }
		 catch(boost::gregorian::bad_day_of_month& bdm) {
			  std::cout << "Invalid day Entered... " << bdm.what() << '\n'
							<< "Using minimum value for day. " << std::endl;

		 }
		 catch(boost::bad_lexical_cast& lex){
			 std::cout << "Wrong Format Entered... " << lex.what() << std::endl;

		 }

	}

	struct datetime{
		 int seconds;
		 int minutes;
		 int nanoseconds;
		 int days;
		 int months;
		 int years;
	};

	static datetime date_diff(const std::string& input_date1_str, const std::string& input_date2_str)
	{
		try{

		  boost::gregorian::date_duration duration = Utils::getDateDuration(input_date1_str, input_date2_str);

		  static const double AVERAGE_DAY_IN_MONTH 	= 30.436875;
		  double dmonths = roundf(((duration.days() + 1) / (AVERAGE_DAY_IN_MONTH)) * 10) / 10;
		  double dyears = floor(round(dmonths / 12));
		  double ddays = floor(((dmonths - (int)dmonths) * AVERAGE_DAY_IN_MONTH)) + 1;

		  datetime date_time;
		  date_time.years = floor(dyears);
		  date_time.months = floor(dmonths);
		  date_time.days = floor(ddays);

		  return date_time;
	  }
	 catch(boost::gregorian::bad_year& by) {
		  std::cout << "Invalid Year Entered: " << by.what() << '\n'
			<< "Using minimum values for month and year." << std::endl;
	 }
	 catch(boost::gregorian::bad_month& bm) {
		  std::cout << "Invalid Month Entered" << bm.what() << '\n'
			<< "Using minimum value for month. " << std::endl;
	 }
	 catch(boost::gregorian::bad_day_of_month& bdm) {
		  std::cout << "Invalid day Entered... " << bdm.what() << '\n'
						<< "Using minimum value for day. " << std::endl;
	 }
	 catch(std::runtime_error& err)
	 {
		 std::cout << "Invalid DateTime Entered... " << err.what() << std::endl;
	 }

	}

	static int get_total_days(datetime dt)
	{
		int dt1;
		dt1 = dt.days + (dt.months*30) + (dt.years*365.25);

		return dt1;
	}

	static datetime timestamp_diff(string input_date1_str, string input_date2_str)
	{
		try{
			  boost::posix_time::ptime t1(boost::posix_time::time_from_string(input_date1_str));
			  boost::posix_time::ptime t2(boost::posix_time::time_from_string(input_date2_str));
			  boost::posix_time::time_duration td = t2-t1;
			  std::cout << to_simple_string(t2) << " - "
							<< to_simple_string(t1) << " = "
							<< to_simple_string(td) << std::endl;

			  int total = td.total_seconds();
			  double numdays = total/(24*3600);
			  double numhr = (total % (24 * 3600)) / 3600;
			  double nummin = ((total % 86400) % 3600) / 60 ;
			  double totalmin = (numhr * 60) + nummin;
			  double numsec = (((total % (24 * 3600)) % 3600) % 60) / 1;

			  cout << "total seconds = " << td.total_seconds() << endl;
			  cout << numdays << ", " << numhr << ", " << nummin << ", " << numsec << endl;

			  static const double AVERAGE_DAY_IN_MONTH 	= 30.436875;
			  double tmonths = numdays/AVERAGE_DAY_IN_MONTH;
			  double tyears = floor(round(tmonths / 12));
			  double tdays = floor(((tmonths - (int)tmonths) * AVERAGE_DAY_IN_MONTH)) + 1;

			  datetime date_time;
			  date_time.years = floor(tyears);
			  date_time.months = floor(tmonths);
			  date_time.days = floor(tdays);
			  date_time.minutes = totalmin;
			  date_time.seconds = numsec;

			  cout << date_time.years << "Year, " << date_time.months << "Months, " << date_time.days << "Days, "
					  << date_time.minutes << "minutes, " << date_time.seconds << "secs "<< endl;
				  return date_time;

			  }
			 catch(boost::gregorian::bad_year& by) {
				  std::cout << "Invalid Year Entered: " << by.what() << '\n'
					<< "Using minimum values for month and year." << std::endl;

			 }
			 catch(boost::gregorian::bad_month& bm) {
				  std::cout << "Invalid Month Entered" << bm.what() << '\n'
					<< "Using minimum value for month. " << std::endl;

			 }
			 catch(boost::gregorian::bad_day_of_month& bdm) {
				  std::cout << "Invalid day Entered... " << bdm.what() << '\n'
								<< "Using minimum value for day. " << std::endl;

			 }
			 catch(boost::bad_lexical_cast& lex){
				 std::cout << "Wrong Format Entered... " << lex.what() << std::endl;

			 }
			 catch(std::runtime_error& err)
			 {
				 std::cout << "Invalid DateTime Entered... " << err.what() << std::endl;
			 }

	}

  static void test(){

//    string numWithCommas = to_string(number);
//    int insertPosition = numWithCommas.length() - 3;
//    while (insertPosition > 0) {
//        numWithCommas.insert(insertPosition, " ");
//        insertPosition-=3;
//    }
//    return numWithCommas;




  }

} /*namespace Util*/

#endif /* LIBUTIL_H_ */
