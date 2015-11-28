#ifndef CPUMOVE_H_
#define CPUMOVE_H_

class cpuMove {
public:
	cpuMove();
	virtual ~cpuMove();
	void cpuMoveinit(char [3][3], int);
	void setEasy(bool);
	int getCPUx();
	int getCPUy();
private:
	bool checkVulnerability(char [3][3]);
	bool checkWinningmove(char [3][3]);
	inline int getRandom(int);
	void putRandom(char [3][3]);
	bool easy;

	int x;
	int y;
};

#endif /* CPUMOVE_H_ */
