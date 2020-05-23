#ifndef MAKEFILE
#define MAKEFILE

#include <string>

class Makefile{

	public:
		Makefile();
		Makefile(const Makefile &mkfl);

		// Getters
		std::string getName(void)const;
		std::string getCompiler(void)const;
		std::string getFormat(void)const;
		std::string getHeader(void)const;
		bool getDebug(void)const;
		bool getValgrind(void)const;
		bool getInstall(void)const;
		bool getCompParam(void)const;
		bool getExecParam(void)const;
		bool getOrganize(void)const;
		std::string getCompParamList(void)const;
		std::string getExecParamList(void)const;
		std::string getFileList(void)const;
		std::string getVersion(void)const;

		// Setters
		void setName(const std::string &name);
		void setCompiler(const std::string &comp);
		void setFormat(const std::string &format);
		void setHeader(const std::string &format);
		void setDebug(const bool &db);
		void setValgrind(const bool &vg);
		void setInstall(const bool &inst);
		void setCompParam(const bool &param);
		void setExecParam(const bool &param);
		void setOrganize(const bool &org);
		void setFileList(const std::string &files);
		void setVersion(const std::string &ver);

		void print(void)const;
		void readCompParam(void);
		void readExecParam(void);
		void printVersion(void)const;
		

	private:
		std::string Name;
		std::string Compiler;
		std::string SourceFormat;
		std::string HeaderFormat;
		bool debugEnable;
		bool valgrindEnable;
		bool installEnable;
		bool parameterEnable;
		bool execParamEnable;
		bool organizeEnable;
		std::string CompParameters;
		std::string ExecParameters;
		std::string FileList;
		std::string Version;
};

#endif