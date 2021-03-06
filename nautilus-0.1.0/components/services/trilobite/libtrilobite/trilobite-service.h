/*
 * This file was generated by orbit-idl - DO NOT EDIT!
 */

#include <glib.h>
#define ORBIT_IDL_SERIAL 9
#include <orb/orbit.h>

#ifndef trilobite_service_H
#define trilobite_service_H 1
#ifdef __cplusplus
extern "C"
{
#endif				/* __cplusplus */

/** typedefs **/
#include <bonobo/Bonobo.h>
#if !defined(ORBIT_DECL_Trilobite_Service) && !defined(_Trilobite_Service_defined)
#define ORBIT_DECL_Trilobite_Service 1
#define _Trilobite_Service_defined 1
#define Trilobite_Service__free CORBA_Object__free
   typedef CORBA_Object Trilobite_Service;
   extern CORBA_unsigned_long Trilobite_Service__classid;
#if !defined(TC_IMPL_TC_Trilobite_Service_0)
#define TC_IMPL_TC_Trilobite_Service_0 't'
#define TC_IMPL_TC_Trilobite_Service_1 'r'
#define TC_IMPL_TC_Trilobite_Service_2 'i'
#define TC_IMPL_TC_Trilobite_Service_3 'l'
#define TC_IMPL_TC_Trilobite_Service_4 'o'
#define TC_IMPL_TC_Trilobite_Service_5 'b'
#define TC_IMPL_TC_Trilobite_Service_6 'i'
#define TC_IMPL_TC_Trilobite_Service_7 't'
#define TC_IMPL_TC_Trilobite_Service_8 'e'
#define TC_IMPL_TC_Trilobite_Service_9 '_'
#define TC_IMPL_TC_Trilobite_Service_10 's'
#define TC_IMPL_TC_Trilobite_Service_11 'e'
#define TC_IMPL_TC_Trilobite_Service_12 'r'
#define TC_IMPL_TC_Trilobite_Service_13 'v'
#define TC_IMPL_TC_Trilobite_Service_14 'i'
#define TC_IMPL_TC_Trilobite_Service_15 'c'
#define TC_IMPL_TC_Trilobite_Service_16 'e'
   extern const struct CORBA_TypeCode_struct TC_Trilobite_Service_struct;
#define TC_Trilobite_Service ((CORBA_TypeCode)&TC_Trilobite_Service_struct)
#endif
#endif
#if !defined(ORBIT_DECL_Trilobite_PasswordQueryClient) && !defined(_Trilobite_PasswordQueryClient_defined)
#define ORBIT_DECL_Trilobite_PasswordQueryClient 1
#define _Trilobite_PasswordQueryClient_defined 1
#define Trilobite_PasswordQueryClient__free CORBA_Object__free
   typedef CORBA_Object Trilobite_PasswordQueryClient;
   extern CORBA_unsigned_long Trilobite_PasswordQueryClient__classid;
#if !defined(TC_IMPL_TC_Trilobite_PasswordQueryClient_0)
#define TC_IMPL_TC_Trilobite_PasswordQueryClient_0 't'
#define TC_IMPL_TC_Trilobite_PasswordQueryClient_1 'r'
#define TC_IMPL_TC_Trilobite_PasswordQueryClient_2 'i'
#define TC_IMPL_TC_Trilobite_PasswordQueryClient_3 'l'
#define TC_IMPL_TC_Trilobite_PasswordQueryClient_4 'o'
#define TC_IMPL_TC_Trilobite_PasswordQueryClient_5 'b'
#define TC_IMPL_TC_Trilobite_PasswordQueryClient_6 'i'
#define TC_IMPL_TC_Trilobite_PasswordQueryClient_7 't'
#define TC_IMPL_TC_Trilobite_PasswordQueryClient_8 'e'
#define TC_IMPL_TC_Trilobite_PasswordQueryClient_9 '_'
#define TC_IMPL_TC_Trilobite_PasswordQueryClient_10 's'
#define TC_IMPL_TC_Trilobite_PasswordQueryClient_11 'e'
#define TC_IMPL_TC_Trilobite_PasswordQueryClient_12 'r'
#define TC_IMPL_TC_Trilobite_PasswordQueryClient_13 'v'
#define TC_IMPL_TC_Trilobite_PasswordQueryClient_14 'i'
#define TC_IMPL_TC_Trilobite_PasswordQueryClient_15 'c'
#define TC_IMPL_TC_Trilobite_PasswordQueryClient_16 'e'
   extern const struct CORBA_TypeCode_struct
      TC_Trilobite_PasswordQueryClient_struct;
#define TC_Trilobite_PasswordQueryClient ((CORBA_TypeCode)&TC_Trilobite_PasswordQueryClient_struct)
#endif
#endif
#if !defined(ORBIT_DECL_Trilobite_PasswordQuery) && !defined(_Trilobite_PasswordQuery_defined)
#define ORBIT_DECL_Trilobite_PasswordQuery 1
#define _Trilobite_PasswordQuery_defined 1
#define Trilobite_PasswordQuery__free CORBA_Object__free
   typedef CORBA_Object Trilobite_PasswordQuery;
   extern CORBA_unsigned_long Trilobite_PasswordQuery__classid;
#if !defined(TC_IMPL_TC_Trilobite_PasswordQuery_0)
#define TC_IMPL_TC_Trilobite_PasswordQuery_0 't'
#define TC_IMPL_TC_Trilobite_PasswordQuery_1 'r'
#define TC_IMPL_TC_Trilobite_PasswordQuery_2 'i'
#define TC_IMPL_TC_Trilobite_PasswordQuery_3 'l'
#define TC_IMPL_TC_Trilobite_PasswordQuery_4 'o'
#define TC_IMPL_TC_Trilobite_PasswordQuery_5 'b'
#define TC_IMPL_TC_Trilobite_PasswordQuery_6 'i'
#define TC_IMPL_TC_Trilobite_PasswordQuery_7 't'
#define TC_IMPL_TC_Trilobite_PasswordQuery_8 'e'
#define TC_IMPL_TC_Trilobite_PasswordQuery_9 '_'
#define TC_IMPL_TC_Trilobite_PasswordQuery_10 's'
#define TC_IMPL_TC_Trilobite_PasswordQuery_11 'e'
#define TC_IMPL_TC_Trilobite_PasswordQuery_12 'r'
#define TC_IMPL_TC_Trilobite_PasswordQuery_13 'v'
#define TC_IMPL_TC_Trilobite_PasswordQuery_14 'i'
#define TC_IMPL_TC_Trilobite_PasswordQuery_15 'c'
#define TC_IMPL_TC_Trilobite_PasswordQuery_16 'e'
   extern const struct CORBA_TypeCode_struct
      TC_Trilobite_PasswordQuery_struct;
#define TC_Trilobite_PasswordQuery ((CORBA_TypeCode)&TC_Trilobite_PasswordQuery_struct)
#endif
#endif

/** POA structures **/
   typedef struct
   {
      void *_private;
      CORBA_char *(*get_name) (PortableServer_Servant _servant,
			       CORBA_Environment * ev);
      CORBA_char *(*get_version) (PortableServer_Servant _servant,
				  CORBA_Environment * ev);
      CORBA_char *(*get_vendor_name) (PortableServer_Servant _servant,
				      CORBA_Environment * ev);
      CORBA_char *(*get_vendor_url) (PortableServer_Servant _servant,
				     CORBA_Environment * ev);
      CORBA_char *(*get_url) (PortableServer_Servant _servant,
			      CORBA_Environment * ev);
      CORBA_char *(*get_icon) (PortableServer_Servant _servant,
			       CORBA_Environment * ev);
   }
   POA_Trilobite_Service__epv;
   typedef struct
   {
      PortableServer_ServantBase__epv *_base_epv;
      POA_Bonobo_Unknown__epv *Bonobo_Unknown_epv;
      POA_Trilobite_Service__epv *Trilobite_Service_epv;
   }
   POA_Trilobite_Service__vepv;
   typedef struct
   {
      void *_private;
      POA_Trilobite_Service__vepv *vepv;
   }
   POA_Trilobite_Service;
   extern void POA_Trilobite_Service__init(PortableServer_Servant servant,
					   CORBA_Environment * ev);
   extern void POA_Trilobite_Service__fini(PortableServer_Servant servant,
					   CORBA_Environment * ev);
   typedef struct
   {
      void *_private;
      CORBA_char *(*get_password) (PortableServer_Servant _servant,
				   const CORBA_char * prompt,
				   CORBA_Environment * ev);
   }
   POA_Trilobite_PasswordQueryClient__epv;
   typedef struct
   {
      PortableServer_ServantBase__epv *_base_epv;
      POA_Bonobo_Unknown__epv *Bonobo_Unknown_epv;
      POA_Trilobite_PasswordQueryClient__epv
	 *Trilobite_PasswordQueryClient_epv;
   }
   POA_Trilobite_PasswordQueryClient__vepv;
   typedef struct
   {
      void *_private;
      POA_Trilobite_PasswordQueryClient__vepv *vepv;
   }
   POA_Trilobite_PasswordQueryClient;
   extern void POA_Trilobite_PasswordQueryClient__init(PortableServer_Servant
						       servant,
						       CORBA_Environment *
						       ev);
   extern void POA_Trilobite_PasswordQueryClient__fini(PortableServer_Servant
						       servant,
						       CORBA_Environment *
						       ev);
   typedef struct
   {
      void *_private;
      void (*set_query_client) (PortableServer_Servant _servant,
				const Trilobite_PasswordQueryClient client,
				CORBA_Environment * ev);
   }
   POA_Trilobite_PasswordQuery__epv;
   typedef struct
   {
      PortableServer_ServantBase__epv *_base_epv;
      POA_Bonobo_Unknown__epv *Bonobo_Unknown_epv;
      POA_Trilobite_PasswordQuery__epv *Trilobite_PasswordQuery_epv;
   }
   POA_Trilobite_PasswordQuery__vepv;
   typedef struct
   {
      void *_private;
      POA_Trilobite_PasswordQuery__vepv *vepv;
   }
   POA_Trilobite_PasswordQuery;
   extern void POA_Trilobite_PasswordQuery__init(PortableServer_Servant
						 servant,
						 CORBA_Environment * ev);
   extern void POA_Trilobite_PasswordQuery__fini(PortableServer_Servant
						 servant,
						 CORBA_Environment * ev);

/** prototypes **/
#define Trilobite_Service_ref Bonobo_Unknown_ref
#define Trilobite_Service_unref Bonobo_Unknown_unref
#define Trilobite_Service_query_interface Bonobo_Unknown_query_interface
   CORBA_char *Trilobite_Service_get_name(Trilobite_Service _obj,
					  CORBA_Environment * ev);
   CORBA_char *Trilobite_Service_get_version(Trilobite_Service _obj,
					     CORBA_Environment * ev);
   CORBA_char *Trilobite_Service_get_vendor_name(Trilobite_Service _obj,
						 CORBA_Environment * ev);
   CORBA_char *Trilobite_Service_get_vendor_url(Trilobite_Service _obj,
						CORBA_Environment * ev);
   CORBA_char *Trilobite_Service_get_url(Trilobite_Service _obj,
					 CORBA_Environment * ev);
   CORBA_char *Trilobite_Service_get_icon(Trilobite_Service _obj,
					  CORBA_Environment * ev);
#define Trilobite_PasswordQueryClient_ref Bonobo_Unknown_ref
#define Trilobite_PasswordQueryClient_unref Bonobo_Unknown_unref
#define Trilobite_PasswordQueryClient_query_interface Bonobo_Unknown_query_interface
   CORBA_char
      *Trilobite_PasswordQueryClient_get_password
      (Trilobite_PasswordQueryClient _obj, const CORBA_char * prompt,
       CORBA_Environment * ev);
#define Trilobite_PasswordQuery_ref Bonobo_Unknown_ref
#define Trilobite_PasswordQuery_unref Bonobo_Unknown_unref
#define Trilobite_PasswordQuery_query_interface Bonobo_Unknown_query_interface
   void Trilobite_PasswordQuery_set_query_client(Trilobite_PasswordQuery _obj,
						 const
						 Trilobite_PasswordQueryClient
						 client,
						 CORBA_Environment * ev);

   void _ORBIT_skel_Trilobite_Service_get_name(POA_Trilobite_Service *
					       _ORBIT_servant,
					       GIOPRecvBuffer *
					       _ORBIT_recv_buffer,
					       CORBA_Environment * ev,
					       CORBA_char *
					       (*_impl_get_name)
					       (PortableServer_Servant
						_servant,
						CORBA_Environment * ev));
   void _ORBIT_skel_Trilobite_Service_get_version(POA_Trilobite_Service *
						  _ORBIT_servant,
						  GIOPRecvBuffer *
						  _ORBIT_recv_buffer,
						  CORBA_Environment * ev,
						  CORBA_char *
						  (*_impl_get_version)
						  (PortableServer_Servant
						   _servant,
						   CORBA_Environment * ev));
   void _ORBIT_skel_Trilobite_Service_get_vendor_name(POA_Trilobite_Service *
						      _ORBIT_servant,
						      GIOPRecvBuffer *
						      _ORBIT_recv_buffer,
						      CORBA_Environment * ev,
						      CORBA_char *
						      (*_impl_get_vendor_name)
						      (PortableServer_Servant
						       _servant,
						       CORBA_Environment *
						       ev));
   void _ORBIT_skel_Trilobite_Service_get_vendor_url(POA_Trilobite_Service *
						     _ORBIT_servant,
						     GIOPRecvBuffer *
						     _ORBIT_recv_buffer,
						     CORBA_Environment * ev,
						     CORBA_char *
						     (*_impl_get_vendor_url)
						     (PortableServer_Servant
						      _servant,
						      CORBA_Environment *
						      ev));
   void _ORBIT_skel_Trilobite_Service_get_url(POA_Trilobite_Service *
					      _ORBIT_servant,
					      GIOPRecvBuffer *
					      _ORBIT_recv_buffer,
					      CORBA_Environment * ev,
					      CORBA_char *
					      (*_impl_get_url)
					      (PortableServer_Servant
					       _servant,
					       CORBA_Environment * ev));
   void _ORBIT_skel_Trilobite_Service_get_icon(POA_Trilobite_Service *
					       _ORBIT_servant,
					       GIOPRecvBuffer *
					       _ORBIT_recv_buffer,
					       CORBA_Environment * ev,
					       CORBA_char *
					       (*_impl_get_icon)
					       (PortableServer_Servant
						_servant,
						CORBA_Environment * ev));
   void
      _ORBIT_skel_Trilobite_PasswordQueryClient_get_password
      (POA_Trilobite_PasswordQueryClient * _ORBIT_servant,
       GIOPRecvBuffer * _ORBIT_recv_buffer, CORBA_Environment * ev,
       CORBA_char * (*_impl_get_password) (PortableServer_Servant _servant,
					   const CORBA_char * prompt,
					   CORBA_Environment * ev));
   void
      _ORBIT_skel_Trilobite_PasswordQuery_set_query_client
      (POA_Trilobite_PasswordQuery * _ORBIT_servant,
       GIOPRecvBuffer * _ORBIT_recv_buffer, CORBA_Environment * ev,
       void (*_impl_set_query_client) (PortableServer_Servant _servant,
				       const Trilobite_PasswordQueryClient
				       client, CORBA_Environment * ev));
#ifdef __cplusplus
}
#endif				/* __cplusplus */

#endif
#undef ORBIT_IDL_SERIAL
