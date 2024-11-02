/*
 * CS106L Assignment 5: TreeBook
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include <iostream>
#include <string>

class User
{
public:
  User(const std::string& name);
  void add_friend(const std::string& name);
  std::string get_name() const;
  size_t size() const;
  void set_friend(size_t index, const std::string& name);
  friend std::ostream &operator<<(std::ostream &out, const User &user);
  ~User();
  User(const User &user);
  User &operator=(const User &user);
  User(User &&user) = delete;
  User &operator=(User &&user) = delete;
  User &operator+=(User &other);
  bool operator<(const User &other) const;

private:
  std::string _name;
  std::string* _friends;
  size_t _size;
  size_t _capacity;
};