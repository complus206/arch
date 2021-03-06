/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef reserve_TYPES_H
#define reserve_TYPES_H

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>





typedef struct _Reserve__isset {
  _Reserve__isset() : reser_no(false), card_no(false), hotel_id(false), room_type_id(false), arrive_date(false), leave_date(false), time_early(false), time_late(false), num_room(false), currency_ID(false), add_bed(false), guest_name(false), guest_type(false), guest_sex(false), contacter(false), contacter_mobile(false), contacter_sex(false), reser_status(false), reser_status1(false), settle_status(false), print_status(false), fax_status(false), email(false), fax(false), phone(false), confirm_method(false), confirm_client(false), confirm_date(false), other(false), other_enable(false), op_user(false), op_date(false), es(false), payment(false), inspector(false), lastchecked_date(false), amendor(false), amend_date(false), sum_price(false), sum_sign(false), num_night(false), room_no(false), arrive_now(false), price_changed(false), double_credit(false), add_bed_price(false), add_bed_num(false), op_ip(false), hotel_confirm_num(false), additional_status(false), hotel_credit(false), additional_statusI(false), Room_Credit(false), Guest_Info(false), gage_status(false), halfday_price(false), halfday_sign_price(false), gs_es(false), gp_settle_status(false), guest_country(false), guest_num(false), payment_way(false), payhotel_status(false), trans_num(false), order_from(false), price_source_type(false), room_num_type(false), hotel_price_statu(false), room_unique_id(false), Credit_Card_No(false), Phone_Type(false), Contacter_Mobile_Type(false) {}
  bool reser_no;
  bool card_no;
  bool hotel_id;
  bool room_type_id;
  bool arrive_date;
  bool leave_date;
  bool time_early;
  bool time_late;
  bool num_room;
  bool currency_ID;
  bool add_bed;
  bool guest_name;
  bool guest_type;
  bool guest_sex;
  bool contacter;
  bool contacter_mobile;
  bool contacter_sex;
  bool reser_status;
  bool reser_status1;
  bool settle_status;
  bool print_status;
  bool fax_status;
  bool email;
  bool fax;
  bool phone;
  bool confirm_method;
  bool confirm_client;
  bool confirm_date;
  bool other;
  bool other_enable;
  bool op_user;
  bool op_date;
  bool es;
  bool payment;
  bool inspector;
  bool lastchecked_date;
  bool amendor;
  bool amend_date;
  bool sum_price;
  bool sum_sign;
  bool num_night;
  bool room_no;
  bool arrive_now;
  bool price_changed;
  bool double_credit;
  bool add_bed_price;
  bool add_bed_num;
  bool op_ip;
  bool hotel_confirm_num;
  bool additional_status;
  bool hotel_credit;
  bool additional_statusI;
  bool Room_Credit;
  bool Guest_Info;
  bool gage_status;
  bool halfday_price;
  bool halfday_sign_price;
  bool gs_es;
  bool gp_settle_status;
  bool guest_country;
  bool guest_num;
  bool payment_way;
  bool payhotel_status;
  bool trans_num;
  bool order_from;
  bool price_source_type;
  bool room_num_type;
  bool hotel_price_statu;
  bool room_unique_id;
  bool Credit_Card_No;
  bool Phone_Type;
  bool Contacter_Mobile_Type;
} _Reserve__isset;

class Reserve {
 public:

  static const char* ascii_fingerprint; // = "475E93A1FFF3F7162E18A2434378C299";
  static const uint8_t binary_fingerprint[16]; // = {0x47,0x5E,0x93,0xA1,0xFF,0xF3,0xF7,0x16,0x2E,0x18,0xA2,0x43,0x43,0x78,0xC2,0x99};

  Reserve() : reser_no(0), card_no(0), hotel_id(), room_type_id(), arrive_date(0), leave_date(0), time_early(), time_late(), num_room(0), currency_ID(), add_bed(0), guest_name(), guest_type(), guest_sex(), contacter(), contacter_mobile(), contacter_sex(), reser_status(), reser_status1(), settle_status(), print_status(0), fax_status(0), email(), fax(), phone(), confirm_method(), confirm_client(), confirm_date(0), other(), other_enable(0), op_user(), op_date(0), es(), payment(), inspector(), lastchecked_date(0), amendor(), amend_date(0), sum_price(), sum_sign(), num_night(), room_no(), arrive_now(0), price_changed(), double_credit(), add_bed_price(), add_bed_num(0), op_ip(), hotel_confirm_num(), additional_status(0), hotel_credit(0), additional_statusI(0), Room_Credit(0), Guest_Info(), gage_status(0), halfday_price(), halfday_sign_price(), gs_es(), gp_settle_status(0), guest_country(), guest_num(0), payment_way(0), payhotel_status(0), trans_num(), order_from(0), price_source_type(0), room_num_type(0), hotel_price_statu(), room_unique_id(), Credit_Card_No(), Phone_Type(0), Contacter_Mobile_Type(0) {
  }

  virtual ~Reserve() throw() {}

  int32_t reser_no;
  int64_t card_no;
  std::string hotel_id;
  std::string room_type_id;
  int64_t arrive_date;
  int64_t leave_date;
  std::string time_early;
  std::string time_late;
  int16_t num_room;
  std::string currency_ID;
  bool add_bed;
  std::string guest_name;
  std::string guest_type;
  std::string guest_sex;
  std::string contacter;
  std::string contacter_mobile;
  std::string contacter_sex;
  std::string reser_status;
  std::string reser_status1;
  std::string settle_status;
  int8_t print_status;
  int8_t fax_status;
  std::string email;
  std::string fax;
  std::string phone;
  std::string confirm_method;
  std::string confirm_client;
  int64_t confirm_date;
  std::string other;
  int8_t other_enable;
  std::string op_user;
  int64_t op_date;
  std::string es;
  std::string payment;
  std::string inspector;
  int64_t lastchecked_date;
  std::string amendor;
  int64_t amend_date;
  std::string sum_price;
  std::string sum_sign;
  std::string num_night;
  std::string room_no;
  int8_t arrive_now;
  std::string price_changed;
  std::string double_credit;
  std::string add_bed_price;
  int8_t add_bed_num;
  std::string op_ip;
  std::string hotel_confirm_num;
  int32_t additional_status;
  int16_t hotel_credit;
  int32_t additional_statusI;
  int8_t Room_Credit;
  std::string Guest_Info;
  int8_t gage_status;
  std::string halfday_price;
  std::string halfday_sign_price;
  std::string gs_es;
  int8_t gp_settle_status;
  std::string guest_country;
  int32_t guest_num;
  int8_t payment_way;
  int8_t payhotel_status;
  std::string trans_num;
  int32_t order_from;
  int8_t price_source_type;
  int8_t room_num_type;
  std::string hotel_price_statu;
  std::string room_unique_id;
  std::string Credit_Card_No;
  int8_t Phone_Type;
  int8_t Contacter_Mobile_Type;

  _Reserve__isset __isset;

  void __set_reser_no(const int32_t val) {
    reser_no = val;
  }

  void __set_card_no(const int64_t val) {
    card_no = val;
  }

  void __set_hotel_id(const std::string& val) {
    hotel_id = val;
  }

  void __set_room_type_id(const std::string& val) {
    room_type_id = val;
  }

  void __set_arrive_date(const int64_t val) {
    arrive_date = val;
  }

  void __set_leave_date(const int64_t val) {
    leave_date = val;
  }

  void __set_time_early(const std::string& val) {
    time_early = val;
  }

  void __set_time_late(const std::string& val) {
    time_late = val;
  }

  void __set_num_room(const int16_t val) {
    num_room = val;
  }

  void __set_currency_ID(const std::string& val) {
    currency_ID = val;
  }

  void __set_add_bed(const bool val) {
    add_bed = val;
  }

  void __set_guest_name(const std::string& val) {
    guest_name = val;
  }

  void __set_guest_type(const std::string& val) {
    guest_type = val;
  }

  void __set_guest_sex(const std::string& val) {
    guest_sex = val;
  }

  void __set_contacter(const std::string& val) {
    contacter = val;
  }

  void __set_contacter_mobile(const std::string& val) {
    contacter_mobile = val;
  }

  void __set_contacter_sex(const std::string& val) {
    contacter_sex = val;
  }

  void __set_reser_status(const std::string& val) {
    reser_status = val;
  }

  void __set_reser_status1(const std::string& val) {
    reser_status1 = val;
  }

  void __set_settle_status(const std::string& val) {
    settle_status = val;
  }

  void __set_print_status(const int8_t val) {
    print_status = val;
  }

  void __set_fax_status(const int8_t val) {
    fax_status = val;
  }

  void __set_email(const std::string& val) {
    email = val;
  }

  void __set_fax(const std::string& val) {
    fax = val;
  }

  void __set_phone(const std::string& val) {
    phone = val;
  }

  void __set_confirm_method(const std::string& val) {
    confirm_method = val;
  }

  void __set_confirm_client(const std::string& val) {
    confirm_client = val;
  }

  void __set_confirm_date(const int64_t val) {
    confirm_date = val;
  }

  void __set_other(const std::string& val) {
    other = val;
  }

  void __set_other_enable(const int8_t val) {
    other_enable = val;
  }

  void __set_op_user(const std::string& val) {
    op_user = val;
  }

  void __set_op_date(const int64_t val) {
    op_date = val;
  }

  void __set_es(const std::string& val) {
    es = val;
  }

  void __set_payment(const std::string& val) {
    payment = val;
  }

  void __set_inspector(const std::string& val) {
    inspector = val;
  }

  void __set_lastchecked_date(const int64_t val) {
    lastchecked_date = val;
  }

  void __set_amendor(const std::string& val) {
    amendor = val;
  }

  void __set_amend_date(const int64_t val) {
    amend_date = val;
  }

  void __set_sum_price(const std::string& val) {
    sum_price = val;
  }

  void __set_sum_sign(const std::string& val) {
    sum_sign = val;
  }

  void __set_num_night(const std::string& val) {
    num_night = val;
  }

  void __set_room_no(const std::string& val) {
    room_no = val;
  }

  void __set_arrive_now(const int8_t val) {
    arrive_now = val;
  }

  void __set_price_changed(const std::string& val) {
    price_changed = val;
  }

  void __set_double_credit(const std::string& val) {
    double_credit = val;
  }

  void __set_add_bed_price(const std::string& val) {
    add_bed_price = val;
  }

  void __set_add_bed_num(const int8_t val) {
    add_bed_num = val;
  }

  void __set_op_ip(const std::string& val) {
    op_ip = val;
  }

  void __set_hotel_confirm_num(const std::string& val) {
    hotel_confirm_num = val;
  }

  void __set_additional_status(const int32_t val) {
    additional_status = val;
  }

  void __set_hotel_credit(const int16_t val) {
    hotel_credit = val;
  }

  void __set_additional_statusI(const int32_t val) {
    additional_statusI = val;
  }

  void __set_Room_Credit(const int8_t val) {
    Room_Credit = val;
  }

  void __set_Guest_Info(const std::string& val) {
    Guest_Info = val;
  }

  void __set_gage_status(const int8_t val) {
    gage_status = val;
  }

  void __set_halfday_price(const std::string& val) {
    halfday_price = val;
  }

  void __set_halfday_sign_price(const std::string& val) {
    halfday_sign_price = val;
  }

  void __set_gs_es(const std::string& val) {
    gs_es = val;
  }

  void __set_gp_settle_status(const int8_t val) {
    gp_settle_status = val;
  }

  void __set_guest_country(const std::string& val) {
    guest_country = val;
  }

  void __set_guest_num(const int32_t val) {
    guest_num = val;
  }

  void __set_payment_way(const int8_t val) {
    payment_way = val;
  }

  void __set_payhotel_status(const int8_t val) {
    payhotel_status = val;
  }

  void __set_trans_num(const std::string& val) {
    trans_num = val;
  }

  void __set_order_from(const int32_t val) {
    order_from = val;
  }

  void __set_price_source_type(const int8_t val) {
    price_source_type = val;
  }

  void __set_room_num_type(const int8_t val) {
    room_num_type = val;
  }

  void __set_hotel_price_statu(const std::string& val) {
    hotel_price_statu = val;
  }

  void __set_room_unique_id(const std::string& val) {
    room_unique_id = val;
  }

  void __set_Credit_Card_No(const std::string& val) {
    Credit_Card_No = val;
  }

  void __set_Phone_Type(const int8_t val) {
    Phone_Type = val;
  }

  void __set_Contacter_Mobile_Type(const int8_t val) {
    Contacter_Mobile_Type = val;
  }

  bool operator == (const Reserve & rhs) const
  {
    if (!(reser_no == rhs.reser_no))
      return false;
    if (!(card_no == rhs.card_no))
      return false;
    if (!(hotel_id == rhs.hotel_id))
      return false;
    if (!(room_type_id == rhs.room_type_id))
      return false;
    if (!(arrive_date == rhs.arrive_date))
      return false;
    if (!(leave_date == rhs.leave_date))
      return false;
    if (!(time_early == rhs.time_early))
      return false;
    if (!(time_late == rhs.time_late))
      return false;
    if (!(num_room == rhs.num_room))
      return false;
    if (!(currency_ID == rhs.currency_ID))
      return false;
    if (!(add_bed == rhs.add_bed))
      return false;
    if (!(guest_name == rhs.guest_name))
      return false;
    if (!(guest_type == rhs.guest_type))
      return false;
    if (!(guest_sex == rhs.guest_sex))
      return false;
    if (!(contacter == rhs.contacter))
      return false;
    if (!(contacter_mobile == rhs.contacter_mobile))
      return false;
    if (!(contacter_sex == rhs.contacter_sex))
      return false;
    if (!(reser_status == rhs.reser_status))
      return false;
    if (!(reser_status1 == rhs.reser_status1))
      return false;
    if (!(settle_status == rhs.settle_status))
      return false;
    if (!(print_status == rhs.print_status))
      return false;
    if (!(fax_status == rhs.fax_status))
      return false;
    if (!(email == rhs.email))
      return false;
    if (!(fax == rhs.fax))
      return false;
    if (!(phone == rhs.phone))
      return false;
    if (!(confirm_method == rhs.confirm_method))
      return false;
    if (!(confirm_client == rhs.confirm_client))
      return false;
    if (!(confirm_date == rhs.confirm_date))
      return false;
    if (!(other == rhs.other))
      return false;
    if (!(other_enable == rhs.other_enable))
      return false;
    if (!(op_user == rhs.op_user))
      return false;
    if (!(op_date == rhs.op_date))
      return false;
    if (!(es == rhs.es))
      return false;
    if (!(payment == rhs.payment))
      return false;
    if (!(inspector == rhs.inspector))
      return false;
    if (!(lastchecked_date == rhs.lastchecked_date))
      return false;
    if (!(amendor == rhs.amendor))
      return false;
    if (!(amend_date == rhs.amend_date))
      return false;
    if (!(sum_price == rhs.sum_price))
      return false;
    if (!(sum_sign == rhs.sum_sign))
      return false;
    if (!(num_night == rhs.num_night))
      return false;
    if (!(room_no == rhs.room_no))
      return false;
    if (!(arrive_now == rhs.arrive_now))
      return false;
    if (!(price_changed == rhs.price_changed))
      return false;
    if (!(double_credit == rhs.double_credit))
      return false;
    if (!(add_bed_price == rhs.add_bed_price))
      return false;
    if (!(add_bed_num == rhs.add_bed_num))
      return false;
    if (!(op_ip == rhs.op_ip))
      return false;
    if (!(hotel_confirm_num == rhs.hotel_confirm_num))
      return false;
    if (!(additional_status == rhs.additional_status))
      return false;
    if (!(hotel_credit == rhs.hotel_credit))
      return false;
    if (!(additional_statusI == rhs.additional_statusI))
      return false;
    if (!(Room_Credit == rhs.Room_Credit))
      return false;
    if (!(Guest_Info == rhs.Guest_Info))
      return false;
    if (!(gage_status == rhs.gage_status))
      return false;
    if (!(halfday_price == rhs.halfday_price))
      return false;
    if (!(halfday_sign_price == rhs.halfday_sign_price))
      return false;
    if (!(gs_es == rhs.gs_es))
      return false;
    if (!(gp_settle_status == rhs.gp_settle_status))
      return false;
    if (!(guest_country == rhs.guest_country))
      return false;
    if (!(guest_num == rhs.guest_num))
      return false;
    if (!(payment_way == rhs.payment_way))
      return false;
    if (!(payhotel_status == rhs.payhotel_status))
      return false;
    if (!(trans_num == rhs.trans_num))
      return false;
    if (!(order_from == rhs.order_from))
      return false;
    if (!(price_source_type == rhs.price_source_type))
      return false;
    if (!(room_num_type == rhs.room_num_type))
      return false;
    if (!(hotel_price_statu == rhs.hotel_price_statu))
      return false;
    if (!(room_unique_id == rhs.room_unique_id))
      return false;
    if (!(Credit_Card_No == rhs.Credit_Card_No))
      return false;
    if (!(Phone_Type == rhs.Phone_Type))
      return false;
    if (!(Contacter_Mobile_Type == rhs.Contacter_Mobile_Type))
      return false;
    return true;
  }
  bool operator != (const Reserve &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Reserve & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(Reserve &a, Reserve &b);



#endif
