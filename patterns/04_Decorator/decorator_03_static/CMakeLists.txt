target_sources(04_Decorator PUBLIC
        FILE_SET decorator_static
        TYPE CXX_MODULES
        FILES main_static.ixx
        BufferedInputStreamStatic.ixx
        BufferedOutputStreamStatic.ixx
        DecryptedInputStreamStatic.ixx
        EncryptedOutputStreamStatic.ixx
        FileInputStreamStatic.ixx
        FileOutputStreamStatic.ixx
        InputStreamStatic.ixx
        OutputStreamStatic.ixx
        OutputStreamDecoratorStatic.ixx
        TemplateConcepts.ixx
)