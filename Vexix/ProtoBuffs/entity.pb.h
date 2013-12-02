// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: entity.proto

#ifndef PROTOBUF_entity_2eproto__INCLUDED
#define PROTOBUF_entity_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_entity_2eproto();
void protobuf_AssignDesc_entity_2eproto();
void protobuf_ShutdownFile_entity_2eproto();

class EntityDesc;
class EntityDesc_Component;

// ===================================================================

class EntityDesc_Component : public ::google::protobuf::Message {
 public:
  EntityDesc_Component();
  virtual ~EntityDesc_Component();

  EntityDesc_Component(const EntityDesc_Component& from);

  inline EntityDesc_Component& operator=(const EntityDesc_Component& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const EntityDesc_Component& default_instance();

  void Swap(EntityDesc_Component* other);

  // implements Message ----------------------------------------------

  EntityDesc_Component* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const EntityDesc_Component& from);
  void MergeFrom(const EntityDesc_Component& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string name = 3;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 3;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  inline void set_allocated_name(::std::string* name);

  // @@protoc_insertion_point(class_scope:EntityDesc.Component)
 private:
  inline void set_has_name();
  inline void clear_has_name();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* name_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_entity_2eproto();
  friend void protobuf_AssignDesc_entity_2eproto();
  friend void protobuf_ShutdownFile_entity_2eproto();

  void InitAsDefaultInstance();
  static EntityDesc_Component* default_instance_;
};
// -------------------------------------------------------------------

class EntityDesc : public ::google::protobuf::Message {
 public:
  EntityDesc();
  virtual ~EntityDesc();

  EntityDesc(const EntityDesc& from);

  inline EntityDesc& operator=(const EntityDesc& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const EntityDesc& default_instance();

  void Swap(EntityDesc* other);

  // implements Message ----------------------------------------------

  EntityDesc* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const EntityDesc& from);
  void MergeFrom(const EntityDesc& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef EntityDesc_Component Component;

  // accessors -------------------------------------------------------

  // required string name = 1;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 1;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  inline void set_allocated_name(::std::string* name);

  // repeated group Component = 2 {
  inline int component_size() const;
  inline void clear_component();
  static const int kComponentFieldNumber = 2;
  inline const ::EntityDesc_Component& component(int index) const;
  inline ::EntityDesc_Component* mutable_component(int index);
  inline ::EntityDesc_Component* add_component();
  inline const ::google::protobuf::RepeatedPtrField< ::EntityDesc_Component >&
      component() const;
  inline ::google::protobuf::RepeatedPtrField< ::EntityDesc_Component >*
      mutable_component();

  // @@protoc_insertion_point(class_scope:EntityDesc)
 private:
  inline void set_has_name();
  inline void clear_has_name();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* name_;
  ::google::protobuf::RepeatedPtrField< ::EntityDesc_Component > component_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_entity_2eproto();
  friend void protobuf_AssignDesc_entity_2eproto();
  friend void protobuf_ShutdownFile_entity_2eproto();

  void InitAsDefaultInstance();
  static EntityDesc* default_instance_;
};
// ===================================================================


// ===================================================================

// EntityDesc_Component

// required string name = 3;
inline bool EntityDesc_Component::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void EntityDesc_Component::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void EntityDesc_Component::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void EntityDesc_Component::clear_name() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& EntityDesc_Component::name() const {
  return *name_;
}
inline void EntityDesc_Component::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void EntityDesc_Component::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void EntityDesc_Component::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* EntityDesc_Component::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  return name_;
}
inline ::std::string* EntityDesc_Component::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void EntityDesc_Component::set_allocated_name(::std::string* name) {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (name) {
    set_has_name();
    name_ = name;
  } else {
    clear_has_name();
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// -------------------------------------------------------------------

// EntityDesc

// required string name = 1;
inline bool EntityDesc::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void EntityDesc::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void EntityDesc::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void EntityDesc::clear_name() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& EntityDesc::name() const {
  return *name_;
}
inline void EntityDesc::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void EntityDesc::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void EntityDesc::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* EntityDesc::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  return name_;
}
inline ::std::string* EntityDesc::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void EntityDesc::set_allocated_name(::std::string* name) {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (name) {
    set_has_name();
    name_ = name;
  } else {
    clear_has_name();
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// repeated group Component = 2 {
inline int EntityDesc::component_size() const {
  return component_.size();
}
inline void EntityDesc::clear_component() {
  component_.Clear();
}
inline const ::EntityDesc_Component& EntityDesc::component(int index) const {
  return component_.Get(index);
}
inline ::EntityDesc_Component* EntityDesc::mutable_component(int index) {
  return component_.Mutable(index);
}
inline ::EntityDesc_Component* EntityDesc::add_component() {
  return component_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::EntityDesc_Component >&
EntityDesc::component() const {
  return component_;
}
inline ::google::protobuf::RepeatedPtrField< ::EntityDesc_Component >*
EntityDesc::mutable_component() {
  return &component_;
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_entity_2eproto__INCLUDED