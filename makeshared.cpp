#ifndef MAKESHARED
#define MAKESHARED

#define MAKE_SHARED(T)                  \
  typedef std::shared_ptr<T> SharedPtr; \
  typedef std::weak_ptr<T> WeakPtr;     \
  template <class ...P>                 \
  static SharedPtr create(P... arg){return std::shared_ptr<T>(new T(arg...));}

#define MAKE_UNIQUE(T)                  \
  typedef std::unique_ptr<T> UniquePtr; \
  template <class ...P>                 \
  static UniquePtr createUnique(P... arg){return std::unique_ptr<T>(new T(arg...));}

#endif // MAKESHARED
