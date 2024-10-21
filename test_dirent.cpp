#include <iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <chrono>
#include"dirent.h"
using namespace std;

class TimerC
{
public:
	TimerC() : beg_(std::chrono::system_clock::now()) {}
	void reset() { beg_ = std::chrono::system_clock::now(); }

	void out(std::string message = "") {
		auto end = std::chrono::system_clock::now();
		std::cout << message << std::chrono::duration_cast<std::chrono::milliseconds>(end - beg_).count() << "ms" << std::endl;
		reset();
	}
private:
	typedef std::chrono::high_resolution_clock clock_;
	typedef std::chrono::duration<double, std::ratio<1> > second_;
	chrono::time_point<std::chrono::system_clock> beg_;
};

int load_img() {
	std::string path = "E:/0Ruzhong_project/8hui";
	std::string outPath = "C:/Users/Terry/Desktop/1mm/result/20";

	// 获取文件夹中的所有图片文件名并按文件名排序
	std::vector<std::string> imageFiles;
	DIR* dir;
	struct dirent* ent;
	if ((dir = opendir(path.c_str())) != nullptr) {
		while ((ent = readdir(dir)) != nullptr) {
			std::string fileName = ent->d_name;
			std::string extension = "";
			if (fileName.find_last_of(".") != std::string::npos) {
				extension = fileName.substr(fileName.find_last_of("."));
			}
			if (extension == ".png" || extension == ".jpg" || extension == ".jpeg" || extension == ".bmp") {
				imageFiles.push_back(path + "/" + fileName);
			}
		}
		closedir(dir);
	}
	else {
		std::cerr << "Could not open directory." << std::endl;
		return -1;
	}
	std::sort(imageFiles.begin(), imageFiles.end(), [](const std::string& a, const std::string& b) {
		int aNum = std::stoi(std::string(a.begin() + a.find_last_of('/') + 1, a.end() - 4));
		int bNum = std::stoi(std::string(b.begin() + b.find_last_of('/') + 1, b.end() - 4));
		return aNum < bNum;
		});

}
int main()
{
	TimerC time;
	load_img();
	time.out("the cost time:");
	return 1;
}