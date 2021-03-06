
class CGlobalRef
{
private:
	CGlobalRef()
		: m_lRefCnt(0)
	{}
	CGlobalRef(const CGlobalRef& other);
    ~CGlobalRef()
	{}

private:
	long m_lRefCnt;
public:
	void AddRef()
	{
		InterlockedIncrement(&m_lRefCnt);
	}
	void Release()
	{
		InterlockedDecrement(&m_lRefCnt);
	}
	long GetRefCnt()
	{
		return m_lRefCnt;
	}
 
public:
    static CGlobalRef* GetInstance()
    {
        static CGlobalRef ins;
        return &ins;
    }
};
