/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Serv_H
#define Serv_H

#include <thrift/TDispatchProcessor.h>
#include "reserve_types.h"



class ServIf {
 public:
  virtual ~ServIf() {}
  virtual bool create(const Reserve& s) = 0;
  virtual bool createBatch(const std::vector<Reserve> & lst) = 0;
};

class ServIfFactory {
 public:
  typedef ServIf Handler;

  virtual ~ServIfFactory() {}

  virtual ServIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ServIf* /* handler */) = 0;
};

class ServIfSingletonFactory : virtual public ServIfFactory {
 public:
  ServIfSingletonFactory(const boost::shared_ptr<ServIf>& iface) : iface_(iface) {}
  virtual ~ServIfSingletonFactory() {}

  virtual ServIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ServIf* /* handler */) {}

 protected:
  boost::shared_ptr<ServIf> iface_;
};

class ServNull : virtual public ServIf {
 public:
  virtual ~ServNull() {}
  bool create(const Reserve& /* s */) {
    bool _return = false;
    return _return;
  }
  bool createBatch(const std::vector<Reserve> & /* lst */) {
    bool _return = false;
    return _return;
  }
};

typedef struct _Serv_create_args__isset {
  _Serv_create_args__isset() : s(false) {}
  bool s;
} _Serv_create_args__isset;

class Serv_create_args {
 public:

  Serv_create_args() {
  }

  virtual ~Serv_create_args() throw() {}

  Reserve s;

  _Serv_create_args__isset __isset;

  void __set_s(const Reserve& val) {
    s = val;
  }

  bool operator == (const Serv_create_args & rhs) const
  {
    if (!(s == rhs.s))
      return false;
    return true;
  }
  bool operator != (const Serv_create_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Serv_create_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Serv_create_pargs {
 public:


  virtual ~Serv_create_pargs() throw() {}

  const Reserve* s;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Serv_create_result__isset {
  _Serv_create_result__isset() : success(false) {}
  bool success;
} _Serv_create_result__isset;

class Serv_create_result {
 public:

  Serv_create_result() : success(0) {
  }

  virtual ~Serv_create_result() throw() {}

  bool success;

  _Serv_create_result__isset __isset;

  void __set_success(const bool val) {
    success = val;
  }

  bool operator == (const Serv_create_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Serv_create_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Serv_create_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Serv_create_presult__isset {
  _Serv_create_presult__isset() : success(false) {}
  bool success;
} _Serv_create_presult__isset;

class Serv_create_presult {
 public:


  virtual ~Serv_create_presult() throw() {}

  bool* success;

  _Serv_create_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Serv_createBatch_args__isset {
  _Serv_createBatch_args__isset() : lst(false) {}
  bool lst;
} _Serv_createBatch_args__isset;

class Serv_createBatch_args {
 public:

  Serv_createBatch_args() {
  }

  virtual ~Serv_createBatch_args() throw() {}

  std::vector<Reserve>  lst;

  _Serv_createBatch_args__isset __isset;

  void __set_lst(const std::vector<Reserve> & val) {
    lst = val;
  }

  bool operator == (const Serv_createBatch_args & rhs) const
  {
    if (!(lst == rhs.lst))
      return false;
    return true;
  }
  bool operator != (const Serv_createBatch_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Serv_createBatch_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Serv_createBatch_pargs {
 public:


  virtual ~Serv_createBatch_pargs() throw() {}

  const std::vector<Reserve> * lst;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Serv_createBatch_result__isset {
  _Serv_createBatch_result__isset() : success(false) {}
  bool success;
} _Serv_createBatch_result__isset;

class Serv_createBatch_result {
 public:

  Serv_createBatch_result() : success(0) {
  }

  virtual ~Serv_createBatch_result() throw() {}

  bool success;

  _Serv_createBatch_result__isset __isset;

  void __set_success(const bool val) {
    success = val;
  }

  bool operator == (const Serv_createBatch_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Serv_createBatch_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Serv_createBatch_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Serv_createBatch_presult__isset {
  _Serv_createBatch_presult__isset() : success(false) {}
  bool success;
} _Serv_createBatch_presult__isset;

class Serv_createBatch_presult {
 public:


  virtual ~Serv_createBatch_presult() throw() {}

  bool* success;

  _Serv_createBatch_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class ServClient : virtual public ServIf {
 public:
  ServClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  ServClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  bool create(const Reserve& s);
  void send_create(const Reserve& s);
  bool recv_create();
  bool createBatch(const std::vector<Reserve> & lst);
  void send_createBatch(const std::vector<Reserve> & lst);
  bool recv_createBatch();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ServProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<ServIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (ServProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_create(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_createBatch(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ServProcessor(boost::shared_ptr<ServIf> iface) :
    iface_(iface) {
    processMap_["create"] = &ServProcessor::process_create;
    processMap_["createBatch"] = &ServProcessor::process_createBatch;
  }

  virtual ~ServProcessor() {}
};

class ServProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ServProcessorFactory(const ::boost::shared_ptr< ServIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< ServIfFactory > handlerFactory_;
};

class ServMultiface : virtual public ServIf {
 public:
  ServMultiface(std::vector<boost::shared_ptr<ServIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ServMultiface() {}
 protected:
  std::vector<boost::shared_ptr<ServIf> > ifaces_;
  ServMultiface() {}
  void add(boost::shared_ptr<ServIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  bool create(const Reserve& s) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->create(s);
    }
    return ifaces_[i]->create(s);
  }

  bool createBatch(const std::vector<Reserve> & lst) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->createBatch(lst);
    }
    return ifaces_[i]->createBatch(lst);
  }

};

const int INVOKE_TIMES = 10000;

#endif
