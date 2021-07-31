#pragma once
template<typename T>


class Vector{
  public:

    Vector(size_t S=2)
    {
        resize(2);
    }
    ~Vector(){
        delete[] m_Data;
    }

    T& operator[](size_t index) { return m_Data[index]; }
    const T& operator[](size_t index) const { return m_Data[index]; }

    void pushBack(const T& elem){
      if(m_Size >= m_Capacity){
        resize(m_Capacity + m_Capacity/2);
      }
      m_Data[m_Size] = elem;
      m_Size++;

    }

    void pushBack(T&& elem){
      if(m_Size >= m_Capacity){
        resize(m_Capacity + m_Capacity/2);
      }
      m_Data[m_Size] = std::move(elem);
      m_Size++;

    }

    template<typename... Args>
    T& EmplaceBack(Args&&... args){
        if(m_Size >= m_Capacity)
            resize(m_Capacity + m_Capacity/2);
        new(&m_Data[m_Size]) T(std::forward<Args>(args)...);
        return m_Data[m_Size++];
    }

    void PopBack(){
        if(m_Size>0){
            m_Data[m_Size].~T();
            --m_Size;
        }

    }
    T* begin(){
      if(m_Size > 0){
        return &m_Data[0];
      }
      return nullptr;
    }
    
    T* end(){
      if(m_Size > 0){
        return &m_Data[m_Size-1];
      }
      return nullptr;
    }
    constexpr size_t Size() const { return m_Size; }
  private:
    void resize(size_t newCapacity){
        T* newData = new T [newCapacity];
        if(m_Size > newCapacity){
            m_Size = newCapacity;
        }
        for(size_t i = 0; i<m_Size; i++){
            newData[i] = m_Data[i];
        }
        delete[] m_Data; 
        m_Capacity = newCapacity;
        m_Data = newData;
    }
    size_t m_Size = 0;
    size_t m_Capacity;
    T* m_Data = nullptr;
};