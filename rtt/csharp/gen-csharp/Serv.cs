/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using Thrift;
using Thrift.Collections;
using System.Runtime.Serialization;
using Thrift.Protocol;
using Thrift.Transport;

public partial class Serv {
  public interface Iface {
    bool create(Reserve s);
    #if SILVERLIGHT
    IAsyncResult Begin_create(AsyncCallback callback, object state, Reserve s);
    bool End_create(IAsyncResult asyncResult);
    #endif
    bool createBatch(List<Reserve> lst);
    #if SILVERLIGHT
    IAsyncResult Begin_createBatch(AsyncCallback callback, object state, List<Reserve> lst);
    bool End_createBatch(IAsyncResult asyncResult);
    #endif
  }

  public class Client : Iface {
    public Client(TProtocol prot) : this(prot, prot)
    {
    }

    public Client(TProtocol iprot, TProtocol oprot)
    {
      iprot_ = iprot;
      oprot_ = oprot;
    }

    protected TProtocol iprot_;
    protected TProtocol oprot_;
    protected int seqid_;

    public TProtocol InputProtocol
    {
      get { return iprot_; }
    }
    public TProtocol OutputProtocol
    {
      get { return oprot_; }
    }


    
    #if SILVERLIGHT
    public IAsyncResult Begin_create(AsyncCallback callback, object state, Reserve s)
    {
      return send_create(callback, state, s);
    }

    public bool End_create(IAsyncResult asyncResult)
    {
      oprot_.Transport.EndFlush(asyncResult);
      return recv_create();
    }

    #endif

    public bool create(Reserve s)
    {
      #if !SILVERLIGHT
      send_create(s);
      return recv_create();

      #else
      var asyncResult = Begin_create(null, null, s);
      return End_create(asyncResult);

      #endif
    }
    #if SILVERLIGHT
    public IAsyncResult send_create(AsyncCallback callback, object state, Reserve s)
    #else
    public void send_create(Reserve s)
    #endif
    {
      oprot_.WriteMessageBegin(new TMessage("create", TMessageType.Call, seqid_));
      create_args args = new create_args();
      args.S = s;
      args.Write(oprot_);
      oprot_.WriteMessageEnd();
      #if SILVERLIGHT
      return oprot_.Transport.BeginFlush(callback, state);
      #else
      oprot_.Transport.Flush();
      #endif
    }

    public bool recv_create()
    {
      TMessage msg = iprot_.ReadMessageBegin();
      if (msg.Type == TMessageType.Exception) {
        TApplicationException x = TApplicationException.Read(iprot_);
        iprot_.ReadMessageEnd();
        throw x;
      }
      create_result result = new create_result();
      result.Read(iprot_);
      iprot_.ReadMessageEnd();
      if (result.__isset.success) {
        return result.Success;
      }
      throw new TApplicationException(TApplicationException.ExceptionType.MissingResult, "create failed: unknown result");
    }

    
    #if SILVERLIGHT
    public IAsyncResult Begin_createBatch(AsyncCallback callback, object state, List<Reserve> lst)
    {
      return send_createBatch(callback, state, lst);
    }

    public bool End_createBatch(IAsyncResult asyncResult)
    {
      oprot_.Transport.EndFlush(asyncResult);
      return recv_createBatch();
    }

    #endif

    public bool createBatch(List<Reserve> lst)
    {
      #if !SILVERLIGHT
      send_createBatch(lst);
      return recv_createBatch();

      #else
      var asyncResult = Begin_createBatch(null, null, lst);
      return End_createBatch(asyncResult);

      #endif
    }
    #if SILVERLIGHT
    public IAsyncResult send_createBatch(AsyncCallback callback, object state, List<Reserve> lst)
    #else
    public void send_createBatch(List<Reserve> lst)
    #endif
    {
      oprot_.WriteMessageBegin(new TMessage("createBatch", TMessageType.Call, seqid_));
      createBatch_args args = new createBatch_args();
      args.Lst = lst;
      args.Write(oprot_);
      oprot_.WriteMessageEnd();
      #if SILVERLIGHT
      return oprot_.Transport.BeginFlush(callback, state);
      #else
      oprot_.Transport.Flush();
      #endif
    }

    public bool recv_createBatch()
    {
      TMessage msg = iprot_.ReadMessageBegin();
      if (msg.Type == TMessageType.Exception) {
        TApplicationException x = TApplicationException.Read(iprot_);
        iprot_.ReadMessageEnd();
        throw x;
      }
      createBatch_result result = new createBatch_result();
      result.Read(iprot_);
      iprot_.ReadMessageEnd();
      if (result.__isset.success) {
        return result.Success;
      }
      throw new TApplicationException(TApplicationException.ExceptionType.MissingResult, "createBatch failed: unknown result");
    }

  }
  public class Processor : TProcessor {
    public Processor(Iface iface)
    {
      iface_ = iface;
      processMap_["create"] = create_Process;
      processMap_["createBatch"] = createBatch_Process;
    }

    protected delegate void ProcessFunction(int seqid, TProtocol iprot, TProtocol oprot);
    private Iface iface_;
    protected Dictionary<string, ProcessFunction> processMap_ = new Dictionary<string, ProcessFunction>();

    public bool Process(TProtocol iprot, TProtocol oprot)
    {
      try
      {
        TMessage msg = iprot.ReadMessageBegin();
        ProcessFunction fn;
        processMap_.TryGetValue(msg.Name, out fn);
        if (fn == null) {
          TProtocolUtil.Skip(iprot, TType.Struct);
          iprot.ReadMessageEnd();
          TApplicationException x = new TApplicationException (TApplicationException.ExceptionType.UnknownMethod, "Invalid method name: '" + msg.Name + "'");
          oprot.WriteMessageBegin(new TMessage(msg.Name, TMessageType.Exception, msg.SeqID));
          x.Write(oprot);
          oprot.WriteMessageEnd();
          oprot.Transport.Flush();
          return true;
        }
        fn(msg.SeqID, iprot, oprot);
      }
      catch (IOException)
      {
        return false;
      }
      return true;
    }

    public void create_Process(int seqid, TProtocol iprot, TProtocol oprot)
    {
      create_args args = new create_args();
      args.Read(iprot);
      iprot.ReadMessageEnd();
      create_result result = new create_result();
      result.Success = iface_.create(args.S);
      oprot.WriteMessageBegin(new TMessage("create", TMessageType.Reply, seqid)); 
      result.Write(oprot);
      oprot.WriteMessageEnd();
      oprot.Transport.Flush();
    }

    public void createBatch_Process(int seqid, TProtocol iprot, TProtocol oprot)
    {
      createBatch_args args = new createBatch_args();
      args.Read(iprot);
      iprot.ReadMessageEnd();
      createBatch_result result = new createBatch_result();
      result.Success = iface_.createBatch(args.Lst);
      oprot.WriteMessageBegin(new TMessage("createBatch", TMessageType.Reply, seqid)); 
      result.Write(oprot);
      oprot.WriteMessageEnd();
      oprot.Transport.Flush();
    }

  }


  #if !SILVERLIGHT
  [Serializable]
  #endif
  public partial class create_args : TBase
  {
    private Reserve _s;

    public Reserve S
    {
      get
      {
        return _s;
      }
      set
      {
        __isset.s = true;
        this._s = value;
      }
    }


    public Isset __isset;
    #if !SILVERLIGHT
    [Serializable]
    #endif
    public struct Isset {
      public bool s;
    }

    public create_args() {
    }

    public void Read (TProtocol iprot)
    {
      TField field;
      iprot.ReadStructBegin();
      while (true)
      {
        field = iprot.ReadFieldBegin();
        if (field.Type == TType.Stop) { 
          break;
        }
        switch (field.ID)
        {
          case 1:
            if (field.Type == TType.Struct) {
              S = new Reserve();
              S.Read(iprot);
            } else { 
              TProtocolUtil.Skip(iprot, field.Type);
            }
            break;
          default: 
            TProtocolUtil.Skip(iprot, field.Type);
            break;
        }
        iprot.ReadFieldEnd();
      }
      iprot.ReadStructEnd();
    }

    public void Write(TProtocol oprot) {
      TStruct struc = new TStruct("create_args");
      oprot.WriteStructBegin(struc);
      TField field = new TField();
      if (S != null && __isset.s) {
        field.Name = "s";
        field.Type = TType.Struct;
        field.ID = 1;
        oprot.WriteFieldBegin(field);
        S.Write(oprot);
        oprot.WriteFieldEnd();
      }
      oprot.WriteFieldStop();
      oprot.WriteStructEnd();
    }

    public override string ToString() {
      StringBuilder sb = new StringBuilder("create_args(");
      sb.Append("S: ");
      sb.Append(S== null ? "<null>" : S.ToString());
      sb.Append(")");
      return sb.ToString();
    }

  }


  #if !SILVERLIGHT
  [Serializable]
  #endif
  public partial class create_result : TBase
  {
    private bool _success;

    public bool Success
    {
      get
      {
        return _success;
      }
      set
      {
        __isset.success = true;
        this._success = value;
      }
    }


    public Isset __isset;
    #if !SILVERLIGHT
    [Serializable]
    #endif
    public struct Isset {
      public bool success;
    }

    public create_result() {
    }

    public void Read (TProtocol iprot)
    {
      TField field;
      iprot.ReadStructBegin();
      while (true)
      {
        field = iprot.ReadFieldBegin();
        if (field.Type == TType.Stop) { 
          break;
        }
        switch (field.ID)
        {
          case 0:
            if (field.Type == TType.Bool) {
              Success = iprot.ReadBool();
            } else { 
              TProtocolUtil.Skip(iprot, field.Type);
            }
            break;
          default: 
            TProtocolUtil.Skip(iprot, field.Type);
            break;
        }
        iprot.ReadFieldEnd();
      }
      iprot.ReadStructEnd();
    }

    public void Write(TProtocol oprot) {
      TStruct struc = new TStruct("create_result");
      oprot.WriteStructBegin(struc);
      TField field = new TField();

      if (this.__isset.success) {
        field.Name = "Success";
        field.Type = TType.Bool;
        field.ID = 0;
        oprot.WriteFieldBegin(field);
        oprot.WriteBool(Success);
        oprot.WriteFieldEnd();
      }
      oprot.WriteFieldStop();
      oprot.WriteStructEnd();
    }

    public override string ToString() {
      StringBuilder sb = new StringBuilder("create_result(");
      sb.Append("Success: ");
      sb.Append(Success);
      sb.Append(")");
      return sb.ToString();
    }

  }


  #if !SILVERLIGHT
  [Serializable]
  #endif
  public partial class createBatch_args : TBase
  {
    private List<Reserve> _lst;

    public List<Reserve> Lst
    {
      get
      {
        return _lst;
      }
      set
      {
        __isset.lst = true;
        this._lst = value;
      }
    }


    public Isset __isset;
    #if !SILVERLIGHT
    [Serializable]
    #endif
    public struct Isset {
      public bool lst;
    }

    public createBatch_args() {
    }

    public void Read (TProtocol iprot)
    {
      TField field;
      iprot.ReadStructBegin();
      while (true)
      {
        field = iprot.ReadFieldBegin();
        if (field.Type == TType.Stop) { 
          break;
        }
        switch (field.ID)
        {
          case 1:
            if (field.Type == TType.List) {
              {
                Lst = new List<Reserve>();
                TList _list0 = iprot.ReadListBegin();
                for( int _i1 = 0; _i1 < _list0.Count; ++_i1)
                {
                  Reserve _elem2 = new Reserve();
                  _elem2 = new Reserve();
                  _elem2.Read(iprot);
                  Lst.Add(_elem2);
                }
                iprot.ReadListEnd();
              }
            } else { 
              TProtocolUtil.Skip(iprot, field.Type);
            }
            break;
          default: 
            TProtocolUtil.Skip(iprot, field.Type);
            break;
        }
        iprot.ReadFieldEnd();
      }
      iprot.ReadStructEnd();
    }

    public void Write(TProtocol oprot) {
      TStruct struc = new TStruct("createBatch_args");
      oprot.WriteStructBegin(struc);
      TField field = new TField();
      if (Lst != null && __isset.lst) {
        field.Name = "lst";
        field.Type = TType.List;
        field.ID = 1;
        oprot.WriteFieldBegin(field);
        {
          oprot.WriteListBegin(new TList(TType.Struct, Lst.Count));
          foreach (Reserve _iter3 in Lst)
          {
            _iter3.Write(oprot);
          }
          oprot.WriteListEnd();
        }
        oprot.WriteFieldEnd();
      }
      oprot.WriteFieldStop();
      oprot.WriteStructEnd();
    }

    public override string ToString() {
      StringBuilder sb = new StringBuilder("createBatch_args(");
      sb.Append("Lst: ");
      sb.Append(Lst);
      sb.Append(")");
      return sb.ToString();
    }

  }


  #if !SILVERLIGHT
  [Serializable]
  #endif
  public partial class createBatch_result : TBase
  {
    private bool _success;

    public bool Success
    {
      get
      {
        return _success;
      }
      set
      {
        __isset.success = true;
        this._success = value;
      }
    }


    public Isset __isset;
    #if !SILVERLIGHT
    [Serializable]
    #endif
    public struct Isset {
      public bool success;
    }

    public createBatch_result() {
    }

    public void Read (TProtocol iprot)
    {
      TField field;
      iprot.ReadStructBegin();
      while (true)
      {
        field = iprot.ReadFieldBegin();
        if (field.Type == TType.Stop) { 
          break;
        }
        switch (field.ID)
        {
          case 0:
            if (field.Type == TType.Bool) {
              Success = iprot.ReadBool();
            } else { 
              TProtocolUtil.Skip(iprot, field.Type);
            }
            break;
          default: 
            TProtocolUtil.Skip(iprot, field.Type);
            break;
        }
        iprot.ReadFieldEnd();
      }
      iprot.ReadStructEnd();
    }

    public void Write(TProtocol oprot) {
      TStruct struc = new TStruct("createBatch_result");
      oprot.WriteStructBegin(struc);
      TField field = new TField();

      if (this.__isset.success) {
        field.Name = "Success";
        field.Type = TType.Bool;
        field.ID = 0;
        oprot.WriteFieldBegin(field);
        oprot.WriteBool(Success);
        oprot.WriteFieldEnd();
      }
      oprot.WriteFieldStop();
      oprot.WriteStructEnd();
    }

    public override string ToString() {
      StringBuilder sb = new StringBuilder("createBatch_result(");
      sb.Append("Success: ");
      sb.Append(Success);
      sb.Append(")");
      return sb.ToString();
    }

  }

}
