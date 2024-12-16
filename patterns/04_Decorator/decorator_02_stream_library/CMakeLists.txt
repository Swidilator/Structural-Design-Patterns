target_sources(04_Decorator PUBLIC
        FILE_SET decorator_streams
        TYPE CXX_MODULES
        FILES main_stream_library.ixx
        InputStream.ixx
        FileInputStream.ixx
        OutputStream.ixx
        FileOutputStream.ixx
        BufferedInputStream.ixx
        BufferedOutputStream.ixx
        EncryptedOutputStream.ixx
        DecryptedInputStream.ixx
        OutputStreamDecorator.ixx
)
