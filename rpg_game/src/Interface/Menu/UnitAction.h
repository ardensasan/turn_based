#ifndef UNITACTION_H
#define UNITACTION_H
class UnitAction 
{
public:
	static UnitAction* GetInstance() {
		if (s_Instance == nullptr)
			s_Instance = new UnitAction();
		return s_Instance;
	}
private:
	UnitAction();
	static UnitAction* s_Instance;
};
#endif