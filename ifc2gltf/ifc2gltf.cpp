#include <iostream>

#include "../ifc2gltf_share/main.h"

using namespace std;

#include <boost/program_options.hpp>  
namespace po = boost::program_options;

#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;

//test command:
//--i E:\testIFC\cube.ifc --o  cube.gltf 
int main(int argc, char* argv[])
{
	std::string originalFile;
	std::string outputFile;

	[argc, argv, &originalFile, &outputFile]()
	{
		po::options_description desc("Allowed options");
		desc.add_options()
			("help", "print help message.")
			("i", po::value<std::string>(), "original ifc file.")
			("o", po::value<std::string>(), "output glTF2 file.");

		po::variables_map vm;
		po::store(po::parse_command_line(argc, argv, desc), vm);
		po::notify(vm);

		if (vm.count("help"))
		{
			cout << desc << endl;
			return ;
		}
		if (vm.count("i"))
		{
			originalFile = vm["i"].as<std::string>();
		}
		else
		{
			return ;
		}

		if (vm.count("o"))
		{
			outputFile = vm["o"].as<std::string>();
		}

		if (outputFile.empty())
		{
			fs::path f(originalFile.c_str());

			f.replace_extension("gltf");

			outputFile = f.filename().string();//eg: cube.gltf
		}
	}();
	
	if (originalFile.empty())
	{
		return 1;
	}

	cout << "original file is " << originalFile.c_str() << "." << endl;
	cout << "output file is " << outputFile.c_str() << "." << endl;

	cin.get();


	//convert file to glTF data.
	kagula::KagulaGLTFData output;
	kagula::ParseIfcFile(originalFile.c_str(), 
		[](int level,const char* message)->int {
		  cout << "level[" << level << "] message: " << message << endl;
		  return 0;
	    },
		output);

	//write glTF data to disk.

	/*
	//int nR = TestIfcParseLib("E:\\testIFC\\cube.ifc");
	//cout << nR << endl;
	*/

	return 0;
}