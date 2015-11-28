#ifndef MISCELLANEOUS_H_
#define MISCELLANEOUS_H_

class miscellaneous {
public:
	miscellaneous();
	virtual ~miscellaneous();
    int printWelcomeScreen();
private:
    int choiceSelection(int ch);
    void showHelp();
    void showCredits();
    //void exitFunction();
};

#endif /* MISCELLANEOUS_H_ */
