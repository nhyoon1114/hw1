#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{ 

  //if the list is empty
  if (empty()) {
    //then create and update tail_
    Item* i = new Item();
    head_ = i;
    tail_ = i;
  }

  //else if tail is full create a new tail
  else if (tail_->last == ARRSIZE) {
    Item* i = new Item();
    i->prev = tail_;
    tail_->next = i;
    tail_ = i;
    tail_->last = 0;
  }

  size_++;

  //update tail value
  tail_->val[tail_->last] = val;
  tail_->last++;

}

void ULListStr::pop_back()
{    
  //catch where nothing is there
  if (empty()) {
    head_ = NULL;
    return;
  }

  size_--;

  //if size is empty then delete head_
  if (empty()) {
    delete head_;
    head_ = NULL;
    return;
  }
  //if last == 1 then delete tail and set last to ARRSIZE
  else if (tail_->last == 1) {
    tail_ = tail_->prev;
    delete tail_->next;
    tail_->last = ARRSIZE;
  }
  //if last != 1 then it can be decremented correctly
  else {
    tail_->last--;
  }

}

void ULListStr::push_front(const std::string& val)
{
  //if the list is empty
  if (empty()) {
    //then create and update head_
    Item* i = new Item();
    head_ = i;
    tail_ = i;
    head_->first = 1;
    tail_->last = 1;
  }

  //else if head is full then create a new head
  else if (head_->first == 0) {
    Item* i = new Item();
    i->next = head_;
    head_->prev = i;
    head_ = i;
    head_->first = ARRSIZE;
  }

  size_++;
  //update head_ value
  head_->first--;
  head_->val[head_->first] = val;
  
}

void ULListStr::pop_front()
{
  //catch when nothing is there
  if (empty()) {
    return;
  }

  size_--;

  //if size is empty delete head
  if (empty()) {
    delete head_;
    head_ = NULL;
    return;
  }
  //if first is capped then delete head and set first to 0
  else if (head_->first == ARRSIZE - 1) {
    head_ = head_->next;
    delete head_->prev;
    head_->first = 0;
  }
  //if not then first can be incremented properly
  else {
    head_->first++;
  }

}

std::string const & ULListStr::back() const
{
  //returns the value at the pos before tail_last
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const
{
  //returns the value at the pos of head_first
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  //if loc is beyond the size_ then it either does not exist or is junk
  if (loc >= size_) {
    return nullptr;
  }

  //establish starting node and position
  Item* node = head_;
  int index = head_->first;

  //increment the index by 1 loc times
  for (int i = 0; i < loc; i++) {
    index++;
    //if the index hits max cap, move to the next item and reset index to 0
    if (index == ARRSIZE && node != tail_) {
      node = node->next;
      index = 0;
    }
    //if index goes past the final value then return nullptr
    /*else if (node == tail_ && index == tail_->last) {
      return nullptr;
    }*/
  }
  //return value at index of the node where i stopped at
  return &node->val[index];
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
