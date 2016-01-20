/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
#ifndef Q_ZCERT_H
#define Q_ZCERT_H

#include "qczmq.h"

class QT_CZMQ_EXPORT QZcert : public QObject
{
    Q_OBJECT
public:

    //  Copy-construct to return the proper wrapped c types
    QZcert (zcert_t *self, QObject *qObjParent = 0);

    //  Create and initialize a new certificate in memory
    explicit QZcert (QObject *qObjParent = 0);

    //  Accepts public/secret key pair from caller
    static QZcert* newFrom (const byte *publicKey, const byte *secretKey, QObject *qObjParent = 0);

    //  Load certificate from file
    static QZcert* load (const QString &filename, QObject *qObjParent = 0);

    //  Destroy a certificate in memory
    ~QZcert ();

    //  Return public part of key pair as 32-byte binary string
    byte * publicKey ();

    //  Return secret part of key pair as 32-byte binary string
    byte * secretKey ();

    //  Return public part of key pair as Z85 armored string
    const QString publicTxt ();

    //  Return secret part of key pair as Z85 armored string
    const QString secretTxt ();

    //  Set certificate metadata from formatted string.
    void setMeta (const QString &name, const QString &param);

    //  Unset certificate metadata.
    void unsetMeta (const QString &name);

    //  Get metadata value from certificate; if the metadata value doesn't
    //  exist, returns NULL.                                              
    const QString meta (const QString &name);

    //  Get list of metadata fields from certificate. Caller is responsible for
    //  destroying list. Caller should not modify the values of list items.    
    QZlist * metaKeys ();

    //  Save full certificate (public + secret) to file for persistent storage  
    //  This creates one public file and one secret file (filename + "_secret").
    int save (const QString &filename);

    //  Save public certificate only to file for persistent storage
    int savePublic (const QString &filename);

    //  Save secret certificate only to file for persistent storage
    int saveSecret (const QString &filename);

    //  Apply certificate to socket, i.e. use for CURVE security on socket.
    //  If certificate was loaded from public file, the secret key will be 
    //  undefined, and this certificate will not work successfully.        
    void apply (void *zocket);

    //  Return copy of certificate; if certificate is NULL or we exhausted
    //  heap memory, returns NULL.                                        
    QZcert * dup ();

    //  Return true if two certificates have the same keys
    bool eq (QZcert *compare);

    //  Print certificate contents to stdout
    void print ();

    //  DEPRECATED as incompatible with centralized logging
    //  Print certificate contents to open stream          
    void fprint (FILE *file);

    //  Self test of this class
    static void test (bool verbose);

    zcert_t *self;
};
#endif //  Q_ZCERT_H
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
