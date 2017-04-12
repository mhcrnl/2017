/*
 * This file was generated by orbit-idl - DO NOT EDIT!
 */

#include <string.h>
#include "trilobite-service.h"

CORBA_char *
Trilobite_Service_get_name(Trilobite_Service _obj, CORBA_Environment * ev)
{
   register GIOP_unsigned_long _ORBIT_request_id,
    _ORBIT_system_exception_minor;
   register CORBA_completion_status _ORBIT_completion_status;
   register GIOPSendBuffer *_ORBIT_send_buffer;
   register GIOPRecvBuffer *_ORBIT_recv_buffer;
   register GIOPConnection *_cnx;
   CORBA_char *_ORBIT_retval;
   register CORBA_unsigned_long _ORBIT_tmpvar_2;
   CORBA_unsigned_long _ORBIT_tmpvar_3;

   if (_obj->servant && _obj->vepv && Trilobite_Service__classid) {
      _ORBIT_retval =
	 ((POA_Trilobite_Service__epv *) _obj->
	  vepv[Trilobite_Service__classid])->get_name(_obj->servant, ev);
      return _ORBIT_retval;
   }
   _cnx = ORBit_object_get_connection(_obj);
 _ORBIT_retry_request:
   _ORBIT_send_buffer = NULL;
   _ORBIT_recv_buffer = NULL;
   _ORBIT_completion_status = CORBA_COMPLETED_NO;
   _ORBIT_request_id = GPOINTER_TO_UINT(alloca(0));
   {				/* marshalling */
      static const struct
      {
	 CORBA_unsigned_long len;
	 char opname[9];
      }
      _ORBIT_operation_name_data =
      {
      9, "get_name"};
      static const struct iovec _ORBIT_operation_vec =
	 { (gpointer) & _ORBIT_operation_name_data, 13 };

      _ORBIT_send_buffer =
	 giop_send_request_buffer_use(_cnx, NULL, _ORBIT_request_id,
				      CORBA_TRUE,
				      &(_obj->active_profile->object_key_vec),
				      &_ORBIT_operation_vec,
				      &ORBit_default_principal_iovec);

      _ORBIT_system_exception_minor = ex_CORBA_COMM_FAILURE;
      if (!_ORBIT_send_buffer)
	 goto _ORBIT_system_exception;
      giop_send_buffer_write(_ORBIT_send_buffer);
      _ORBIT_completion_status = CORBA_COMPLETED_MAYBE;
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      _ORBIT_send_buffer = NULL;
   }
   {				/* demarshalling */
      register guchar *_ORBIT_curptr;

      _ORBIT_recv_buffer =
	 giop_recv_reply_buffer_use_2(_cnx, _ORBIT_request_id, TRUE);
      if (!_ORBIT_recv_buffer)
	 goto _ORBIT_system_exception;
      _ORBIT_completion_status = CORBA_COMPLETED_YES;
      if (_ORBIT_recv_buffer->message.u.reply.reply_status !=
	  GIOP_NO_EXCEPTION) goto _ORBIT_msg_exception;
      _ORBIT_curptr = GIOP_RECV_BUFFER(_ORBIT_recv_buffer)->cur;
      if (giop_msg_conversion_needed(GIOP_MESSAGE_BUFFER(_ORBIT_recv_buffer))) {
	 _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
	 
	    (*((guint32 *) & (_ORBIT_tmpvar_3))) =
	    GUINT32_SWAP_LE_BE(*((guint32 *) _ORBIT_curptr));
	 _ORBIT_curptr += 4;
	 _ORBIT_retval = CORBA_string_alloc(_ORBIT_tmpvar_3);
	 memcpy(_ORBIT_retval, _ORBIT_curptr,
		sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3);
	 _ORBIT_curptr +=
	    sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3;
      } else {
	 _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
	 _ORBIT_tmpvar_3 = *((CORBA_unsigned_long *) _ORBIT_curptr);
	 _ORBIT_curptr += 4;
	 _ORBIT_retval = CORBA_string_alloc(_ORBIT_tmpvar_3);
	 memcpy(_ORBIT_retval, _ORBIT_curptr,
		sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3);
	 _ORBIT_curptr +=
	    sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3;
      }
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      return _ORBIT_retval;
    _ORBIT_system_exception:
      CORBA_exception_set_system(ev, _ORBIT_system_exception_minor,
				 _ORBIT_completion_status);
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      return _ORBIT_retval;
    _ORBIT_msg_exception:
      if (_ORBIT_recv_buffer->message.u.reply.reply_status ==
	  GIOP_LOCATION_FORWARD) {
	 if (_obj->forward_locations != NULL)
	    ORBit_delete_profiles(_obj->forward_locations);
	 _obj->forward_locations = ORBit_demarshal_IOR(_ORBIT_recv_buffer);
	 _cnx = ORBit_object_get_forwarded_connection(_obj);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);

	 goto _ORBIT_retry_request;
      } else {
	 ORBit_handle_exception(_ORBIT_recv_buffer, ev, NULL, _obj->orb);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);
	 return _ORBIT_retval;
      }
   }
}
CORBA_char *
Trilobite_Service_get_version(Trilobite_Service _obj, CORBA_Environment * ev)
{
   register GIOP_unsigned_long _ORBIT_request_id,
    _ORBIT_system_exception_minor;
   register CORBA_completion_status _ORBIT_completion_status;
   register GIOPSendBuffer *_ORBIT_send_buffer;
   register GIOPRecvBuffer *_ORBIT_recv_buffer;
   register GIOPConnection *_cnx;
   CORBA_char *_ORBIT_retval;
   register CORBA_unsigned_long _ORBIT_tmpvar_2;
   CORBA_unsigned_long _ORBIT_tmpvar_3;

   if (_obj->servant && _obj->vepv && Trilobite_Service__classid) {
      _ORBIT_retval =
	 ((POA_Trilobite_Service__epv *) _obj->
	  vepv[Trilobite_Service__classid])->get_version(_obj->servant, ev);
      return _ORBIT_retval;
   }
   _cnx = ORBit_object_get_connection(_obj);
 _ORBIT_retry_request:
   _ORBIT_send_buffer = NULL;
   _ORBIT_recv_buffer = NULL;
   _ORBIT_completion_status = CORBA_COMPLETED_NO;
   _ORBIT_request_id = GPOINTER_TO_UINT(alloca(0));
   {				/* marshalling */
      static const struct
      {
	 CORBA_unsigned_long len;
	 char opname[12];
      }
      _ORBIT_operation_name_data =
      {
      12, "get_version"};
      static const struct iovec _ORBIT_operation_vec =
	 { (gpointer) & _ORBIT_operation_name_data, 16 };

      _ORBIT_send_buffer =
	 giop_send_request_buffer_use(_cnx, NULL, _ORBIT_request_id,
				      CORBA_TRUE,
				      &(_obj->active_profile->object_key_vec),
				      &_ORBIT_operation_vec,
				      &ORBit_default_principal_iovec);

      _ORBIT_system_exception_minor = ex_CORBA_COMM_FAILURE;
      if (!_ORBIT_send_buffer)
	 goto _ORBIT_system_exception;
      giop_send_buffer_write(_ORBIT_send_buffer);
      _ORBIT_completion_status = CORBA_COMPLETED_MAYBE;
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      _ORBIT_send_buffer = NULL;
   }
   {				/* demarshalling */
      register guchar *_ORBIT_curptr;

      _ORBIT_recv_buffer =
	 giop_recv_reply_buffer_use_2(_cnx, _ORBIT_request_id, TRUE);
      if (!_ORBIT_recv_buffer)
	 goto _ORBIT_system_exception;
      _ORBIT_completion_status = CORBA_COMPLETED_YES;
      if (_ORBIT_recv_buffer->message.u.reply.reply_status !=
	  GIOP_NO_EXCEPTION) goto _ORBIT_msg_exception;
      _ORBIT_curptr = GIOP_RECV_BUFFER(_ORBIT_recv_buffer)->cur;
      if (giop_msg_conversion_needed(GIOP_MESSAGE_BUFFER(_ORBIT_recv_buffer))) {
	 _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
	 
	    (*((guint32 *) & (_ORBIT_tmpvar_3))) =
	    GUINT32_SWAP_LE_BE(*((guint32 *) _ORBIT_curptr));
	 _ORBIT_curptr += 4;
	 _ORBIT_retval = CORBA_string_alloc(_ORBIT_tmpvar_3);
	 memcpy(_ORBIT_retval, _ORBIT_curptr,
		sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3);
	 _ORBIT_curptr +=
	    sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3;
      } else {
	 _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
	 _ORBIT_tmpvar_3 = *((CORBA_unsigned_long *) _ORBIT_curptr);
	 _ORBIT_curptr += 4;
	 _ORBIT_retval = CORBA_string_alloc(_ORBIT_tmpvar_3);
	 memcpy(_ORBIT_retval, _ORBIT_curptr,
		sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3);
	 _ORBIT_curptr +=
	    sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3;
      }
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      return _ORBIT_retval;
    _ORBIT_system_exception:
      CORBA_exception_set_system(ev, _ORBIT_system_exception_minor,
				 _ORBIT_completion_status);
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      return _ORBIT_retval;
    _ORBIT_msg_exception:
      if (_ORBIT_recv_buffer->message.u.reply.reply_status ==
	  GIOP_LOCATION_FORWARD) {
	 if (_obj->forward_locations != NULL)
	    ORBit_delete_profiles(_obj->forward_locations);
	 _obj->forward_locations = ORBit_demarshal_IOR(_ORBIT_recv_buffer);
	 _cnx = ORBit_object_get_forwarded_connection(_obj);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);

	 goto _ORBIT_retry_request;
      } else {
	 ORBit_handle_exception(_ORBIT_recv_buffer, ev, NULL, _obj->orb);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);
	 return _ORBIT_retval;
      }
   }
}
CORBA_char *
Trilobite_Service_get_vendor_name(Trilobite_Service _obj,
				  CORBA_Environment * ev)
{
   register GIOP_unsigned_long _ORBIT_request_id,
    _ORBIT_system_exception_minor;
   register CORBA_completion_status _ORBIT_completion_status;
   register GIOPSendBuffer *_ORBIT_send_buffer;
   register GIOPRecvBuffer *_ORBIT_recv_buffer;
   register GIOPConnection *_cnx;
   CORBA_char *_ORBIT_retval;
   register CORBA_unsigned_long _ORBIT_tmpvar_2;
   CORBA_unsigned_long _ORBIT_tmpvar_3;

   if (_obj->servant && _obj->vepv && Trilobite_Service__classid) {
      _ORBIT_retval =
	 ((POA_Trilobite_Service__epv *) _obj->
	  vepv[Trilobite_Service__classid])->get_vendor_name(_obj->servant,
							     ev);
      return _ORBIT_retval;
   }
   _cnx = ORBit_object_get_connection(_obj);
 _ORBIT_retry_request:
   _ORBIT_send_buffer = NULL;
   _ORBIT_recv_buffer = NULL;
   _ORBIT_completion_status = CORBA_COMPLETED_NO;
   _ORBIT_request_id = GPOINTER_TO_UINT(alloca(0));
   {				/* marshalling */
      static const struct
      {
	 CORBA_unsigned_long len;
	 char opname[16];
      }
      _ORBIT_operation_name_data =
      {
      16, "get_vendor_name"};
      static const struct iovec _ORBIT_operation_vec =
	 { (gpointer) & _ORBIT_operation_name_data, 20 };

      _ORBIT_send_buffer =
	 giop_send_request_buffer_use(_cnx, NULL, _ORBIT_request_id,
				      CORBA_TRUE,
				      &(_obj->active_profile->object_key_vec),
				      &_ORBIT_operation_vec,
				      &ORBit_default_principal_iovec);

      _ORBIT_system_exception_minor = ex_CORBA_COMM_FAILURE;
      if (!_ORBIT_send_buffer)
	 goto _ORBIT_system_exception;
      giop_send_buffer_write(_ORBIT_send_buffer);
      _ORBIT_completion_status = CORBA_COMPLETED_MAYBE;
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      _ORBIT_send_buffer = NULL;
   }
   {				/* demarshalling */
      register guchar *_ORBIT_curptr;

      _ORBIT_recv_buffer =
	 giop_recv_reply_buffer_use_2(_cnx, _ORBIT_request_id, TRUE);
      if (!_ORBIT_recv_buffer)
	 goto _ORBIT_system_exception;
      _ORBIT_completion_status = CORBA_COMPLETED_YES;
      if (_ORBIT_recv_buffer->message.u.reply.reply_status !=
	  GIOP_NO_EXCEPTION) goto _ORBIT_msg_exception;
      _ORBIT_curptr = GIOP_RECV_BUFFER(_ORBIT_recv_buffer)->cur;
      if (giop_msg_conversion_needed(GIOP_MESSAGE_BUFFER(_ORBIT_recv_buffer))) {
	 _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
	 
	    (*((guint32 *) & (_ORBIT_tmpvar_3))) =
	    GUINT32_SWAP_LE_BE(*((guint32 *) _ORBIT_curptr));
	 _ORBIT_curptr += 4;
	 _ORBIT_retval = CORBA_string_alloc(_ORBIT_tmpvar_3);
	 memcpy(_ORBIT_retval, _ORBIT_curptr,
		sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3);
	 _ORBIT_curptr +=
	    sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3;
      } else {
	 _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
	 _ORBIT_tmpvar_3 = *((CORBA_unsigned_long *) _ORBIT_curptr);
	 _ORBIT_curptr += 4;
	 _ORBIT_retval = CORBA_string_alloc(_ORBIT_tmpvar_3);
	 memcpy(_ORBIT_retval, _ORBIT_curptr,
		sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3);
	 _ORBIT_curptr +=
	    sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3;
      }
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      return _ORBIT_retval;
    _ORBIT_system_exception:
      CORBA_exception_set_system(ev, _ORBIT_system_exception_minor,
				 _ORBIT_completion_status);
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      return _ORBIT_retval;
    _ORBIT_msg_exception:
      if (_ORBIT_recv_buffer->message.u.reply.reply_status ==
	  GIOP_LOCATION_FORWARD) {
	 if (_obj->forward_locations != NULL)
	    ORBit_delete_profiles(_obj->forward_locations);
	 _obj->forward_locations = ORBit_demarshal_IOR(_ORBIT_recv_buffer);
	 _cnx = ORBit_object_get_forwarded_connection(_obj);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);

	 goto _ORBIT_retry_request;
      } else {
	 ORBit_handle_exception(_ORBIT_recv_buffer, ev, NULL, _obj->orb);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);
	 return _ORBIT_retval;
      }
   }
}
CORBA_char *
Trilobite_Service_get_vendor_url(Trilobite_Service _obj,
				 CORBA_Environment * ev)
{
   register GIOP_unsigned_long _ORBIT_request_id,
    _ORBIT_system_exception_minor;
   register CORBA_completion_status _ORBIT_completion_status;
   register GIOPSendBuffer *_ORBIT_send_buffer;
   register GIOPRecvBuffer *_ORBIT_recv_buffer;
   register GIOPConnection *_cnx;
   CORBA_char *_ORBIT_retval;
   register CORBA_unsigned_long _ORBIT_tmpvar_2;
   CORBA_unsigned_long _ORBIT_tmpvar_3;

   if (_obj->servant && _obj->vepv && Trilobite_Service__classid) {
      _ORBIT_retval =
	 ((POA_Trilobite_Service__epv *) _obj->
	  vepv[Trilobite_Service__classid])->get_vendor_url(_obj->servant,
							    ev);
      return _ORBIT_retval;
   }
   _cnx = ORBit_object_get_connection(_obj);
 _ORBIT_retry_request:
   _ORBIT_send_buffer = NULL;
   _ORBIT_recv_buffer = NULL;
   _ORBIT_completion_status = CORBA_COMPLETED_NO;
   _ORBIT_request_id = GPOINTER_TO_UINT(alloca(0));
   {				/* marshalling */
      static const struct
      {
	 CORBA_unsigned_long len;
	 char opname[15];
      }
      _ORBIT_operation_name_data =
      {
      15, "get_vendor_url"};
      static const struct iovec _ORBIT_operation_vec =
	 { (gpointer) & _ORBIT_operation_name_data, 19 };

      _ORBIT_send_buffer =
	 giop_send_request_buffer_use(_cnx, NULL, _ORBIT_request_id,
				      CORBA_TRUE,
				      &(_obj->active_profile->object_key_vec),
				      &_ORBIT_operation_vec,
				      &ORBit_default_principal_iovec);

      _ORBIT_system_exception_minor = ex_CORBA_COMM_FAILURE;
      if (!_ORBIT_send_buffer)
	 goto _ORBIT_system_exception;
      giop_send_buffer_write(_ORBIT_send_buffer);
      _ORBIT_completion_status = CORBA_COMPLETED_MAYBE;
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      _ORBIT_send_buffer = NULL;
   }
   {				/* demarshalling */
      register guchar *_ORBIT_curptr;

      _ORBIT_recv_buffer =
	 giop_recv_reply_buffer_use_2(_cnx, _ORBIT_request_id, TRUE);
      if (!_ORBIT_recv_buffer)
	 goto _ORBIT_system_exception;
      _ORBIT_completion_status = CORBA_COMPLETED_YES;
      if (_ORBIT_recv_buffer->message.u.reply.reply_status !=
	  GIOP_NO_EXCEPTION) goto _ORBIT_msg_exception;
      _ORBIT_curptr = GIOP_RECV_BUFFER(_ORBIT_recv_buffer)->cur;
      if (giop_msg_conversion_needed(GIOP_MESSAGE_BUFFER(_ORBIT_recv_buffer))) {
	 _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
	 
	    (*((guint32 *) & (_ORBIT_tmpvar_3))) =
	    GUINT32_SWAP_LE_BE(*((guint32 *) _ORBIT_curptr));
	 _ORBIT_curptr += 4;
	 _ORBIT_retval = CORBA_string_alloc(_ORBIT_tmpvar_3);
	 memcpy(_ORBIT_retval, _ORBIT_curptr,
		sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3);
	 _ORBIT_curptr +=
	    sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3;
      } else {
	 _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
	 _ORBIT_tmpvar_3 = *((CORBA_unsigned_long *) _ORBIT_curptr);
	 _ORBIT_curptr += 4;
	 _ORBIT_retval = CORBA_string_alloc(_ORBIT_tmpvar_3);
	 memcpy(_ORBIT_retval, _ORBIT_curptr,
		sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3);
	 _ORBIT_curptr +=
	    sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3;
      }
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      return _ORBIT_retval;
    _ORBIT_system_exception:
      CORBA_exception_set_system(ev, _ORBIT_system_exception_minor,
				 _ORBIT_completion_status);
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      return _ORBIT_retval;
    _ORBIT_msg_exception:
      if (_ORBIT_recv_buffer->message.u.reply.reply_status ==
	  GIOP_LOCATION_FORWARD) {
	 if (_obj->forward_locations != NULL)
	    ORBit_delete_profiles(_obj->forward_locations);
	 _obj->forward_locations = ORBit_demarshal_IOR(_ORBIT_recv_buffer);
	 _cnx = ORBit_object_get_forwarded_connection(_obj);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);

	 goto _ORBIT_retry_request;
      } else {
	 ORBit_handle_exception(_ORBIT_recv_buffer, ev, NULL, _obj->orb);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);
	 return _ORBIT_retval;
      }
   }
}
CORBA_char *
Trilobite_Service_get_url(Trilobite_Service _obj, CORBA_Environment * ev)
{
   register GIOP_unsigned_long _ORBIT_request_id,
    _ORBIT_system_exception_minor;
   register CORBA_completion_status _ORBIT_completion_status;
   register GIOPSendBuffer *_ORBIT_send_buffer;
   register GIOPRecvBuffer *_ORBIT_recv_buffer;
   register GIOPConnection *_cnx;
   CORBA_char *_ORBIT_retval;
   register CORBA_unsigned_long _ORBIT_tmpvar_2;
   CORBA_unsigned_long _ORBIT_tmpvar_3;

   if (_obj->servant && _obj->vepv && Trilobite_Service__classid) {
      _ORBIT_retval =
	 ((POA_Trilobite_Service__epv *) _obj->
	  vepv[Trilobite_Service__classid])->get_url(_obj->servant, ev);
      return _ORBIT_retval;
   }
   _cnx = ORBit_object_get_connection(_obj);
 _ORBIT_retry_request:
   _ORBIT_send_buffer = NULL;
   _ORBIT_recv_buffer = NULL;
   _ORBIT_completion_status = CORBA_COMPLETED_NO;
   _ORBIT_request_id = GPOINTER_TO_UINT(alloca(0));
   {				/* marshalling */
      static const struct
      {
	 CORBA_unsigned_long len;
	 char opname[8];
      }
      _ORBIT_operation_name_data =
      {
      8, "get_url"};
      static const struct iovec _ORBIT_operation_vec =
	 { (gpointer) & _ORBIT_operation_name_data, 12 };

      _ORBIT_send_buffer =
	 giop_send_request_buffer_use(_cnx, NULL, _ORBIT_request_id,
				      CORBA_TRUE,
				      &(_obj->active_profile->object_key_vec),
				      &_ORBIT_operation_vec,
				      &ORBit_default_principal_iovec);

      _ORBIT_system_exception_minor = ex_CORBA_COMM_FAILURE;
      if (!_ORBIT_send_buffer)
	 goto _ORBIT_system_exception;
      giop_send_buffer_write(_ORBIT_send_buffer);
      _ORBIT_completion_status = CORBA_COMPLETED_MAYBE;
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      _ORBIT_send_buffer = NULL;
   }
   {				/* demarshalling */
      register guchar *_ORBIT_curptr;

      _ORBIT_recv_buffer =
	 giop_recv_reply_buffer_use_2(_cnx, _ORBIT_request_id, TRUE);
      if (!_ORBIT_recv_buffer)
	 goto _ORBIT_system_exception;
      _ORBIT_completion_status = CORBA_COMPLETED_YES;
      if (_ORBIT_recv_buffer->message.u.reply.reply_status !=
	  GIOP_NO_EXCEPTION) goto _ORBIT_msg_exception;
      _ORBIT_curptr = GIOP_RECV_BUFFER(_ORBIT_recv_buffer)->cur;
      if (giop_msg_conversion_needed(GIOP_MESSAGE_BUFFER(_ORBIT_recv_buffer))) {
	 _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
	 
	    (*((guint32 *) & (_ORBIT_tmpvar_3))) =
	    GUINT32_SWAP_LE_BE(*((guint32 *) _ORBIT_curptr));
	 _ORBIT_curptr += 4;
	 _ORBIT_retval = CORBA_string_alloc(_ORBIT_tmpvar_3);
	 memcpy(_ORBIT_retval, _ORBIT_curptr,
		sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3);
	 _ORBIT_curptr +=
	    sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3;
      } else {
	 _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
	 _ORBIT_tmpvar_3 = *((CORBA_unsigned_long *) _ORBIT_curptr);
	 _ORBIT_curptr += 4;
	 _ORBIT_retval = CORBA_string_alloc(_ORBIT_tmpvar_3);
	 memcpy(_ORBIT_retval, _ORBIT_curptr,
		sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3);
	 _ORBIT_curptr +=
	    sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3;
      }
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      return _ORBIT_retval;
    _ORBIT_system_exception:
      CORBA_exception_set_system(ev, _ORBIT_system_exception_minor,
				 _ORBIT_completion_status);
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      return _ORBIT_retval;
    _ORBIT_msg_exception:
      if (_ORBIT_recv_buffer->message.u.reply.reply_status ==
	  GIOP_LOCATION_FORWARD) {
	 if (_obj->forward_locations != NULL)
	    ORBit_delete_profiles(_obj->forward_locations);
	 _obj->forward_locations = ORBit_demarshal_IOR(_ORBIT_recv_buffer);
	 _cnx = ORBit_object_get_forwarded_connection(_obj);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);

	 goto _ORBIT_retry_request;
      } else {
	 ORBit_handle_exception(_ORBIT_recv_buffer, ev, NULL, _obj->orb);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);
	 return _ORBIT_retval;
      }
   }
}
CORBA_char *
Trilobite_Service_get_icon(Trilobite_Service _obj, CORBA_Environment * ev)
{
   register GIOP_unsigned_long _ORBIT_request_id,
    _ORBIT_system_exception_minor;
   register CORBA_completion_status _ORBIT_completion_status;
   register GIOPSendBuffer *_ORBIT_send_buffer;
   register GIOPRecvBuffer *_ORBIT_recv_buffer;
   register GIOPConnection *_cnx;
   CORBA_char *_ORBIT_retval;
   register CORBA_unsigned_long _ORBIT_tmpvar_2;
   CORBA_unsigned_long _ORBIT_tmpvar_3;

   if (_obj->servant && _obj->vepv && Trilobite_Service__classid) {
      _ORBIT_retval =
	 ((POA_Trilobite_Service__epv *) _obj->
	  vepv[Trilobite_Service__classid])->get_icon(_obj->servant, ev);
      return _ORBIT_retval;
   }
   _cnx = ORBit_object_get_connection(_obj);
 _ORBIT_retry_request:
   _ORBIT_send_buffer = NULL;
   _ORBIT_recv_buffer = NULL;
   _ORBIT_completion_status = CORBA_COMPLETED_NO;
   _ORBIT_request_id = GPOINTER_TO_UINT(alloca(0));
   {				/* marshalling */
      static const struct
      {
	 CORBA_unsigned_long len;
	 char opname[9];
      }
      _ORBIT_operation_name_data =
      {
      9, "get_icon"};
      static const struct iovec _ORBIT_operation_vec =
	 { (gpointer) & _ORBIT_operation_name_data, 13 };

      _ORBIT_send_buffer =
	 giop_send_request_buffer_use(_cnx, NULL, _ORBIT_request_id,
				      CORBA_TRUE,
				      &(_obj->active_profile->object_key_vec),
				      &_ORBIT_operation_vec,
				      &ORBit_default_principal_iovec);

      _ORBIT_system_exception_minor = ex_CORBA_COMM_FAILURE;
      if (!_ORBIT_send_buffer)
	 goto _ORBIT_system_exception;
      giop_send_buffer_write(_ORBIT_send_buffer);
      _ORBIT_completion_status = CORBA_COMPLETED_MAYBE;
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      _ORBIT_send_buffer = NULL;
   }
   {				/* demarshalling */
      register guchar *_ORBIT_curptr;

      _ORBIT_recv_buffer =
	 giop_recv_reply_buffer_use_2(_cnx, _ORBIT_request_id, TRUE);
      if (!_ORBIT_recv_buffer)
	 goto _ORBIT_system_exception;
      _ORBIT_completion_status = CORBA_COMPLETED_YES;
      if (_ORBIT_recv_buffer->message.u.reply.reply_status !=
	  GIOP_NO_EXCEPTION) goto _ORBIT_msg_exception;
      _ORBIT_curptr = GIOP_RECV_BUFFER(_ORBIT_recv_buffer)->cur;
      if (giop_msg_conversion_needed(GIOP_MESSAGE_BUFFER(_ORBIT_recv_buffer))) {
	 _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
	 
	    (*((guint32 *) & (_ORBIT_tmpvar_3))) =
	    GUINT32_SWAP_LE_BE(*((guint32 *) _ORBIT_curptr));
	 _ORBIT_curptr += 4;
	 _ORBIT_retval = CORBA_string_alloc(_ORBIT_tmpvar_3);
	 memcpy(_ORBIT_retval, _ORBIT_curptr,
		sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3);
	 _ORBIT_curptr +=
	    sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3;
      } else {
	 _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
	 _ORBIT_tmpvar_3 = *((CORBA_unsigned_long *) _ORBIT_curptr);
	 _ORBIT_curptr += 4;
	 _ORBIT_retval = CORBA_string_alloc(_ORBIT_tmpvar_3);
	 memcpy(_ORBIT_retval, _ORBIT_curptr,
		sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3);
	 _ORBIT_curptr +=
	    sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3;
      }
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      return _ORBIT_retval;
    _ORBIT_system_exception:
      CORBA_exception_set_system(ev, _ORBIT_system_exception_minor,
				 _ORBIT_completion_status);
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      return _ORBIT_retval;
    _ORBIT_msg_exception:
      if (_ORBIT_recv_buffer->message.u.reply.reply_status ==
	  GIOP_LOCATION_FORWARD) {
	 if (_obj->forward_locations != NULL)
	    ORBit_delete_profiles(_obj->forward_locations);
	 _obj->forward_locations = ORBit_demarshal_IOR(_ORBIT_recv_buffer);
	 _cnx = ORBit_object_get_forwarded_connection(_obj);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);

	 goto _ORBIT_retry_request;
      } else {
	 ORBit_handle_exception(_ORBIT_recv_buffer, ev, NULL, _obj->orb);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);
	 return _ORBIT_retval;
      }
   }
}
CORBA_char *
Trilobite_PasswordQueryClient_get_password(Trilobite_PasswordQueryClient _obj,
					   const CORBA_char * prompt,
					   CORBA_Environment * ev)
{
   register GIOP_unsigned_long _ORBIT_request_id,
    _ORBIT_system_exception_minor;
   register CORBA_completion_status _ORBIT_completion_status;
   register GIOPSendBuffer *_ORBIT_send_buffer;
   register GIOPRecvBuffer *_ORBIT_recv_buffer;
   register GIOPConnection *_cnx;
   CORBA_char *_ORBIT_retval;
   register CORBA_unsigned_long _ORBIT_tmpvar_4;
   CORBA_unsigned_long _ORBIT_tmpvar_5;

   if (_obj->servant && _obj->vepv && Trilobite_PasswordQueryClient__classid) {
      _ORBIT_retval =
	 ((POA_Trilobite_PasswordQueryClient__epv *) _obj->
	  vepv[Trilobite_PasswordQueryClient__classid])->get_password(_obj->
								      servant,
								      prompt,
								      ev);
      return _ORBIT_retval;
   }
   _cnx = ORBit_object_get_connection(_obj);
 _ORBIT_retry_request:
   _ORBIT_send_buffer = NULL;
   _ORBIT_recv_buffer = NULL;
   _ORBIT_completion_status = CORBA_COMPLETED_NO;
   _ORBIT_request_id = GPOINTER_TO_UINT(alloca(0));
   {				/* marshalling */
      static const struct
      {
	 CORBA_unsigned_long len;
	 char opname[13];
      }
      _ORBIT_operation_name_data =
      {
      13, "get_password"};
      static const struct iovec _ORBIT_operation_vec =
	 { (gpointer) & _ORBIT_operation_name_data, 17 };
      register CORBA_unsigned_long _ORBIT_tmpvar_0;
      CORBA_unsigned_long _ORBIT_tmpvar_1;

      _ORBIT_send_buffer =
	 giop_send_request_buffer_use(_cnx, NULL, _ORBIT_request_id,
				      CORBA_TRUE,
				      &(_obj->active_profile->object_key_vec),
				      &_ORBIT_operation_vec,
				      &ORBit_default_principal_iovec);

      _ORBIT_system_exception_minor = ex_CORBA_COMM_FAILURE;
      if (!_ORBIT_send_buffer)
	 goto _ORBIT_system_exception;
      _ORBIT_tmpvar_1 = strlen(prompt) + 1;
      giop_message_buffer_do_alignment(GIOP_MESSAGE_BUFFER
				       (_ORBIT_send_buffer), 4);
      {
	 guchar *_ORBIT_t;

	 _ORBIT_t = alloca(sizeof(_ORBIT_tmpvar_1));
	 memcpy(_ORBIT_t, &(_ORBIT_tmpvar_1), sizeof(_ORBIT_tmpvar_1));
	 giop_message_buffer_append_mem(GIOP_MESSAGE_BUFFER
					(_ORBIT_send_buffer), (_ORBIT_t),
					sizeof(_ORBIT_tmpvar_1));
      }
      giop_message_buffer_append_mem(GIOP_MESSAGE_BUFFER(_ORBIT_send_buffer),
				     (prompt),
				     sizeof(prompt[_ORBIT_tmpvar_0]) *
				     _ORBIT_tmpvar_1);
      giop_send_buffer_write(_ORBIT_send_buffer);
      _ORBIT_completion_status = CORBA_COMPLETED_MAYBE;
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      _ORBIT_send_buffer = NULL;
   }
   {				/* demarshalling */
      register guchar *_ORBIT_curptr;

      _ORBIT_recv_buffer =
	 giop_recv_reply_buffer_use_2(_cnx, _ORBIT_request_id, TRUE);
      if (!_ORBIT_recv_buffer)
	 goto _ORBIT_system_exception;
      _ORBIT_completion_status = CORBA_COMPLETED_YES;
      if (_ORBIT_recv_buffer->message.u.reply.reply_status !=
	  GIOP_NO_EXCEPTION) goto _ORBIT_msg_exception;
      _ORBIT_curptr = GIOP_RECV_BUFFER(_ORBIT_recv_buffer)->cur;
      if (giop_msg_conversion_needed(GIOP_MESSAGE_BUFFER(_ORBIT_recv_buffer))) {
	 _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
	 
	    (*((guint32 *) & (_ORBIT_tmpvar_5))) =
	    GUINT32_SWAP_LE_BE(*((guint32 *) _ORBIT_curptr));
	 _ORBIT_curptr += 4;
	 _ORBIT_retval = CORBA_string_alloc(_ORBIT_tmpvar_5);
	 memcpy(_ORBIT_retval, _ORBIT_curptr,
		sizeof(_ORBIT_retval[_ORBIT_tmpvar_4]) * _ORBIT_tmpvar_5);
	 _ORBIT_curptr +=
	    sizeof(_ORBIT_retval[_ORBIT_tmpvar_4]) * _ORBIT_tmpvar_5;
      } else {
	 _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
	 _ORBIT_tmpvar_5 = *((CORBA_unsigned_long *) _ORBIT_curptr);
	 _ORBIT_curptr += 4;
	 _ORBIT_retval = CORBA_string_alloc(_ORBIT_tmpvar_5);
	 memcpy(_ORBIT_retval, _ORBIT_curptr,
		sizeof(_ORBIT_retval[_ORBIT_tmpvar_4]) * _ORBIT_tmpvar_5);
	 _ORBIT_curptr +=
	    sizeof(_ORBIT_retval[_ORBIT_tmpvar_4]) * _ORBIT_tmpvar_5;
      }
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      return _ORBIT_retval;
    _ORBIT_system_exception:
      CORBA_exception_set_system(ev, _ORBIT_system_exception_minor,
				 _ORBIT_completion_status);
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      return _ORBIT_retval;
    _ORBIT_msg_exception:
      if (_ORBIT_recv_buffer->message.u.reply.reply_status ==
	  GIOP_LOCATION_FORWARD) {
	 if (_obj->forward_locations != NULL)
	    ORBit_delete_profiles(_obj->forward_locations);
	 _obj->forward_locations = ORBit_demarshal_IOR(_ORBIT_recv_buffer);
	 _cnx = ORBit_object_get_forwarded_connection(_obj);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);

	 goto _ORBIT_retry_request;
      } else {
	 ORBit_handle_exception(_ORBIT_recv_buffer, ev, NULL, _obj->orb);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);
	 return _ORBIT_retval;
      }
   }
}
void
Trilobite_PasswordQuery_set_query_client(Trilobite_PasswordQuery _obj,
					 const Trilobite_PasswordQueryClient
					 client, CORBA_Environment * ev)
{
   register GIOP_unsigned_long _ORBIT_request_id,
    _ORBIT_system_exception_minor;
   register CORBA_completion_status _ORBIT_completion_status;
   register GIOPSendBuffer *_ORBIT_send_buffer;
   register GIOPRecvBuffer *_ORBIT_recv_buffer;
   register GIOPConnection *_cnx;

   if (_obj->servant && _obj->vepv && Trilobite_PasswordQuery__classid) {
      
	 ((POA_Trilobite_PasswordQuery__epv *) _obj->
       vepv[Trilobite_PasswordQuery__classid])->set_query_client(_obj->
								 servant,
								 client, ev);
      return;
   }
   _cnx = ORBit_object_get_connection(_obj);
 _ORBIT_retry_request:
   _ORBIT_send_buffer = NULL;
   _ORBIT_recv_buffer = NULL;
   _ORBIT_completion_status = CORBA_COMPLETED_NO;
   _ORBIT_request_id = GPOINTER_TO_UINT(alloca(0));
   {				/* marshalling */
      static const struct
      {
	 CORBA_unsigned_long len;
	 char opname[17];
      }
      _ORBIT_operation_name_data =
      {
      17, "set_query_client"};
      static const struct iovec _ORBIT_operation_vec =
	 { (gpointer) & _ORBIT_operation_name_data, 21 };

      _ORBIT_send_buffer =
	 giop_send_request_buffer_use(_cnx, NULL, _ORBIT_request_id,
				      CORBA_TRUE,
				      &(_obj->active_profile->object_key_vec),
				      &_ORBIT_operation_vec,
				      &ORBit_default_principal_iovec);

      _ORBIT_system_exception_minor = ex_CORBA_COMM_FAILURE;
      if (!_ORBIT_send_buffer)
	 goto _ORBIT_system_exception;
      ORBit_marshal_object(_ORBIT_send_buffer, client);
      giop_send_buffer_write(_ORBIT_send_buffer);
      _ORBIT_completion_status = CORBA_COMPLETED_MAYBE;
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      _ORBIT_send_buffer = NULL;
   }
   {				/* demarshalling */
      register guchar *_ORBIT_curptr;

      _ORBIT_recv_buffer =
	 giop_recv_reply_buffer_use_2(_cnx, _ORBIT_request_id, TRUE);
      if (!_ORBIT_recv_buffer)
	 goto _ORBIT_system_exception;
      _ORBIT_completion_status = CORBA_COMPLETED_YES;
      if (_ORBIT_recv_buffer->message.u.reply.reply_status !=
	  GIOP_NO_EXCEPTION) goto _ORBIT_msg_exception;
      _ORBIT_curptr = GIOP_RECV_BUFFER(_ORBIT_recv_buffer)->cur;
      if (giop_msg_conversion_needed(GIOP_MESSAGE_BUFFER(_ORBIT_recv_buffer))) {
      } else {
      }
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      return;
    _ORBIT_system_exception:
      CORBA_exception_set_system(ev, _ORBIT_system_exception_minor,
				 _ORBIT_completion_status);
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      return;
    _ORBIT_msg_exception:
      if (_ORBIT_recv_buffer->message.u.reply.reply_status ==
	  GIOP_LOCATION_FORWARD) {
	 if (_obj->forward_locations != NULL)
	    ORBit_delete_profiles(_obj->forward_locations);
	 _obj->forward_locations = ORBit_demarshal_IOR(_ORBIT_recv_buffer);
	 _cnx = ORBit_object_get_forwarded_connection(_obj);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);

	 goto _ORBIT_retry_request;
      } else {
	 ORBit_handle_exception(_ORBIT_recv_buffer, ev, NULL, _obj->orb);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);
	 return;
      }
   }
}
