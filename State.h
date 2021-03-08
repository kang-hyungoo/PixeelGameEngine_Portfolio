#pragma once

class cUnit;
class cEnemy;
class cBullet;

class cState
{
protected:
	cEnemy* mEnemy = nullptr;

public:

	static cState* CreateInstance() { return NULL; }

	void SetEnemy(cEnemy* tEnemy) {
		mEnemy = tEnemy;
	}

	virtual void DoFire(cBullet tpBullet[], cUnit* tpTarget, int tAccuracy) = 0;

protected:
	cState() {};
	virtual ~cState() {};
};

class DoFireAim : public cState {
private:
	static DoFireAim* mpInstance;

protected:
	DoFireAim() { }
	virtual ~DoFireAim() { }

public:
	static DoFireAim* CreateInstance()
	{
		if (NULL == mpInstance) mpInstance = new DoFireAim();

		return mpInstance;
	}

	virtual void DoFire(cBullet tpBullet[], cUnit* tpTarget, int tAccuracy) override;
};

class DoFireCircle : public cState {
private:
	static DoFireCircle* mpInstance;

protected:
	DoFireCircle() { }
	virtual ~DoFireCircle() { }

public:
	static DoFireCircle* CreateInstance()
	{
		if (NULL == mpInstance) mpInstance = new DoFireCircle();

		return mpInstance;
	}

	virtual void DoFire(cBullet tpBullet[], cUnit* tpTarget, int tAccuracy) override;
};