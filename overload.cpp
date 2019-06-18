#include <iostream>
#include <string.h>

class Str {
  private:
  unsigned int len;
  char* buf;
  public:
  Str(char* str, unsigned int inlen = -1) {
  	len = (inlen == (unsigned int)(-1) ? strlen(str) : inlen);
  	buf = (char*)malloc(len);
  	memcpy(buf, str, len);
  }
  Str(const Str& old) {
  	buf = (char*)malloc(old.len);
  	memcpy(buf, old.buf, old.len);
  	len = old.len;
  }
  Str(Str&& old) {
    buf = old.buf;
    len = old.len;
    old.buf = NULL;
  }
  ~Str() {
  	if(buf != NULL) {
  	  free(buf);
  	}
  }
  Str operator+(const Str& old) && {
  	std::cout << "R + L" << std::endl;
  	Str res("", this->len + old.len);
  	memcpy(res.buf + 0, this->buf, this->len);
  	memcpy(res.buf + this->len, old.buf, old.len);
  	return res;
  }
  Str operator+(Str&& old) && {
  	std::cout << "R + R" << std::endl;
  	Str res("", this->len + old.len);
  	memcpy(res.buf + 0, this->buf, this->len);
  	memcpy(res.buf + this->len, old.buf, old.len);
  	return res;
  }
  Str operator+(const Str& old) & {
  	std::cout << "L + L" << std::endl;
  	Str res("", this->len + old.len);
  	memcpy(res.buf + 0, this->buf, this->len);
  	memcpy(res.buf + this->len, old.buf, old.len);
  	return res;
  }
  Str operator+(Str&& old) & {
  	std::cout << "L + R" << std::endl;
  	Str res("", this->len + old.len);
  	memcpy(res.buf + 0, this->buf, this->len);
  	memcpy(res.buf + this->len, old.buf, old.len);
  	return res;
  }
  
  void print() {
  	printf("%.*s\n", this->len, this->buf);
  }
};

int main() {
	Str a("Hello");
	Str b("World");
	Str c = a + (a + a) + b + (b + b);
	c.print();
	return 0;
}
