#ifndef INPUTLISTENER_H
#define INPUTLISTENER_H
class InputListener
{
public:
	static InputListener* GetInstance();
	void Listen();
private:
	InputListener();
	static InputListener* s_instance;
};

#endif
