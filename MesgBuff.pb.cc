// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MesgBuff.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MesgBuff.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* MesgBuff_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MesgBuff_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MesgBuff_2eproto() {
  protobuf_AddDesc_MesgBuff_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MesgBuff.proto");
  GOOGLE_CHECK(file != NULL);
  MesgBuff_descriptor_ = file->message_type(0);
  static const int MesgBuff_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MesgBuff, msg_),
  };
  MesgBuff_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MesgBuff_descriptor_,
      MesgBuff::default_instance_,
      MesgBuff_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MesgBuff, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MesgBuff, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MesgBuff));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MesgBuff_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MesgBuff_descriptor_, &MesgBuff::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MesgBuff_2eproto() {
  delete MesgBuff::default_instance_;
  delete MesgBuff_reflection_;
}

void protobuf_AddDesc_MesgBuff_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\016MesgBuff.proto\"\027\n\010MesgBuff\022\013\n\003msg\030\001 \001("
    "\t", 41);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MesgBuff.proto", &protobuf_RegisterTypes);
  MesgBuff::default_instance_ = new MesgBuff();
  MesgBuff::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MesgBuff_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MesgBuff_2eproto {
  StaticDescriptorInitializer_MesgBuff_2eproto() {
    protobuf_AddDesc_MesgBuff_2eproto();
  }
} static_descriptor_initializer_MesgBuff_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int MesgBuff::kMsgFieldNumber;
#endif  // !_MSC_VER

MesgBuff::MesgBuff()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:MesgBuff)
}

void MesgBuff::InitAsDefaultInstance() {
}

MesgBuff::MesgBuff(const MesgBuff& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:MesgBuff)
}

void MesgBuff::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  msg_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MesgBuff::~MesgBuff() {
  // @@protoc_insertion_point(destructor:MesgBuff)
  SharedDtor();
}

void MesgBuff::SharedDtor() {
  if (msg_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete msg_;
  }
  if (this != default_instance_) {
  }
}

void MesgBuff::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MesgBuff::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MesgBuff_descriptor_;
}

const MesgBuff& MesgBuff::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MesgBuff_2eproto();
  return *default_instance_;
}

MesgBuff* MesgBuff::default_instance_ = NULL;

MesgBuff* MesgBuff::New() const {
  return new MesgBuff;
}

void MesgBuff::Clear() {
  if (has_msg()) {
    if (msg_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
      msg_->clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MesgBuff::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:MesgBuff)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string msg = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_msg()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->msg().data(), this->msg().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "msg");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:MesgBuff)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:MesgBuff)
  return false;
#undef DO_
}

void MesgBuff::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:MesgBuff)
  // optional string msg = 1;
  if (has_msg()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->msg().data(), this->msg().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "msg");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->msg(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:MesgBuff)
}

::google::protobuf::uint8* MesgBuff::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:MesgBuff)
  // optional string msg = 1;
  if (has_msg()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->msg().data(), this->msg().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "msg");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->msg(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:MesgBuff)
  return target;
}

int MesgBuff::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string msg = 1;
    if (has_msg()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->msg());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void MesgBuff::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MesgBuff* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MesgBuff*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MesgBuff::MergeFrom(const MesgBuff& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_msg()) {
      set_msg(from.msg());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MesgBuff::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MesgBuff::CopyFrom(const MesgBuff& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MesgBuff::IsInitialized() const {

  return true;
}

void MesgBuff::Swap(MesgBuff* other) {
  if (other != this) {
    std::swap(msg_, other->msg_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MesgBuff::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MesgBuff_descriptor_;
  metadata.reflection = MesgBuff_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)