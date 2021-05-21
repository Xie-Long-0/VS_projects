#ifndef SEQLIST_H_
#define SEQLIST_H_

/**
 * @brief 顺序存储结构表
 * @author XieLong
 * @date 2021-5
*/

#include <memory>

constexpr auto DEFSIZE = 64;

template<typename Type>
class SeqList
{
private:
	Type *m_vector = nullptr;
	int m_size = 0;
	int m_capacity = 0;
	int m_front = 0;
	// 当size>0时m_rear指向的位置为有效元素，即at(m_rear)返回有效的元素
	int m_rear = -1;
	Type blank_val = Type();

public:
	SeqList();
	SeqList(int size);
	SeqList(const Type &e, int size);
	SeqList(const SeqList<Type> &other);
	SeqList(SeqList<Type> &&other);
	~SeqList();

	int size() const { return m_size; }
	int capacity() const { return m_capacity; }
	bool empty() const { return (m_size <= 0); }
	void clear();
	// 重新分配数组空间大小
	bool resize(int size);
	bool push_front(const Type &e);
	bool push_back(const Type &e);
	bool insert(int pos, const Type &e);
	void erase(int pos);
	void swap(int apos, int bpos);
	Type &at(int i);
	Type at(int i) const;
	
	Type &operator[](int i) { return at(i); }
	SeqList<Type> &operator<<(const Type &e) { push_back(e); return (*this); }

private:
	int local_pos(int pos) const;
	void normalize();
	// 将从begin到end范围的元素左移一位
	bool move_left(int begin, int end);
	// 将从begin到end范围的元素右移一位
	bool move_right(int begin, int end);
};

////////////// 模板类的具体化函数必须可见 ////////////////

template<typename Type>
SeqList<Type>::SeqList()
{
	m_capacity = DEFSIZE;
	m_vector = new Type[m_capacity]{};
}

template<typename Type>
SeqList<Type>::SeqList(int size)
{
	m_capacity = size > 0 ? size : DEFSIZE;
	m_vector = new Type[m_capacity]{};
}

template<typename Type>
SeqList<Type>::SeqList(const Type &e, int size)
{
	m_capacity = size > 0 ? size : DEFSIZE;
	m_vector = new Type[m_capacity];
	m_size = size >= 0 ? size : 0;
	m_rear = m_size - 1;

	for (int i = 0; i < m_size; i++)
	{
		m_vector[i] = e;
	}
}

template<typename Type>
SeqList<Type>::SeqList(const SeqList<Type> &other)
{
	m_capacity = other.m_capacity;
	m_size = other.m_size;
	m_front = 0;
	m_rear = m_size - 1;

	m_vector = new Type[m_capacity];
	for (int i = 0; i < m_size; i++)
	{
		m_vector[i] = other.at(i);
	}
}

template<typename Type>
SeqList<Type>::SeqList(SeqList<Type> &&other)
{
	m_capacity = other.m_capacity;
	m_size = other.m_size;
	m_front = other.m_front;
	m_rear = other.m_rear;

	m_vector = std::move(other.m_vector);
}

template<typename Type>
SeqList<Type>::~SeqList()
{
	if (m_vector) delete[] m_vector;
}

template<typename Type>
bool SeqList<Type>::push_front(const Type &e)
{
	if (m_front <= 0 && !move_right(m_front, m_rear))
		return false;
	m_vector[m_front - 1] = e;
	m_front--;
	m_size++;
	return true;
}

template<typename Type>
bool SeqList<Type>::push_back(const Type &e)
{
	if (m_rear + 1 >= m_capacity)
	{
		if (m_size < m_capacity && m_size < DEFSIZE * 0.5)
		{
			normalize();
		}
		else if (!resize(m_capacity + DEFSIZE))
		{
			return false;
		}
	}

	m_vector[m_rear + 1] = e;
	m_rear++;
	m_size++;
	return true;
}

template<typename Type>
bool SeqList<Type>::insert(int pos, const Type &e)
{
	if (pos <= 0) return push_front(e);
	if (pos > m_rear - m_front) return push_back(e);

	if (m_size >= m_capacity && !resize(m_size + DEFSIZE)) return false;

	// 比较插入位置离前边近还是离后边近
	if (m_front > 0 && (pos < m_rear - m_front - pos))
	{
		if (!move_left(m_front, m_front + pos)) return false;
	}
	else
	{
		if (!move_right(m_front + pos, m_rear)) return false;
	}

	m_vector[m_front + pos] = e;
	return true;
}

template<typename Type>
Type &SeqList<Type>::at(int i)
{
	if (m_size <= 0 || i >= m_size || i < 0)
		return blank_val;
	return m_vector[m_front + i];
}

template<typename Type>
Type SeqList<Type>::at(int i) const
{
	if (m_size <= 0 || i >= m_size || i < 0)
		return Type();
	return m_vector[m_front + i];
}

template<typename Type>
void SeqList<Type>::clear()
{
	m_front = 0;
	m_rear = -1;
	m_size = 0;
	m_capacity = DEFSIZE;
	delete[] m_vector;
	m_vector = new Type[m_capacity]{};
}

template<typename Type>
bool SeqList<Type>::resize(int size)
{
	if (size < m_size) return false;
	if (size == m_capacity) return true;

	// 申请新的空间
	Type *newList = new Type[size];
	if (newList == nullptr) return false;

	for (int i = 0; i < m_size; i++)
	{
		newList[i] = m_vector[i + m_front];
	}

	m_front = 0;
	m_rear = m_size - 1;
	m_capacity = size;
	delete[] m_vector;
	m_vector = newList;

	return true;
}

template<typename Type>
void SeqList<Type>::erase(int pos)
{
	if (m_size <= 0 || pos >= m_size || pos < 0)
		return;

	// 比较删除位置离前边近还是离后边近
	if (m_front > 0 && (pos < m_rear - m_front - pos))
	{
		move_right(m_front, m_front + pos - 1);
	}
	else
	{
		move_left(m_front + pos + 1, m_rear);
	}
}

template<typename Type>
void SeqList<Type>::swap(int apos, int bpos)
{
	if (local_pos(apos) < 0 || local_pos(bpos) < 0)
		return;
	auto tmp = m_vector[local_pos(apos)];
	m_vector[local_pos(apos)] = m_vector[local_pos(bpos)];
	m_vector[local_pos(bpos)] = tmp;
}

template<typename Type>
int SeqList<Type>::local_pos(int pos) const
{
	if (pos < 0 || pos >= m_size)
		return -1;
	return pos + m_front;
}

template<typename Type>
void SeqList<Type>::normalize()
{
	if (m_size <= 0 || m_front == 0)
		return;

	for (int i = 0; i < m_size; i++)
	{
		m_vector[i] = m_vector[m_front + i];
	}
	m_front = 0;
	m_rear = m_size - 1;
}

template<typename Type>
bool SeqList<Type>::move_left(int begin, int end)
{
	begin = begin > m_front ? begin : m_front;
	end = end < m_rear ? end : m_rear;

	if (m_size <= 0 || begin > m_rear || end < begin)
		return false;

	if (begin <= 0)
	{
		m_rear--;
		m_size--;
		return true;
	}

	for (int i = begin; i <= end; i++)
	{
		m_vector[i - 1] = m_vector[i];
	}

	if (m_front > 0 && begin <= m_front)
	{
		m_front--;
		m_size++;
	}
	if (m_rear > 0 && end >= m_rear)
	{
		m_rear--;
		m_size--;
	}
	return true;
}

template<typename Type>
bool SeqList<Type>::move_right(int begin, int end)
{
	begin = begin > m_front ? begin : m_front;
	end = end < m_rear ? end : m_rear;

	if (m_size <= 0 || begin > m_rear || end < begin)
		return false;

	if (end + 1 >= m_capacity)
	{
		begin = begin - m_front;
		if (!resize(m_capacity + DEFSIZE)) return false;
		end = m_rear;
	}

	for (int i = end; i >= begin; i--)
	{
		m_vector[i + 1] = m_vector[i];
	}

	if (begin <= m_front)
	{
		m_front++;
		m_size--;
	}
	if (end >= m_rear)
	{
		m_rear++;
		m_size++;
	}
	return true;
}

#endif  //!SEQLIST_H_
