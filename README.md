Remote File Server over SFTP

To compile project: 
    run: 
        make
    



File Server Command Line Interface

    Available Commands:
        - connect <server_address> <port>: Connect to the server given the specified port and ip

        - login   <username> <pasword>: Log in to the server with the specified credentials

        - ls      <directory_path>: List files and directories in the specified directory

        - cd      <directory_path>: Change the current working directory

        - get     <file_path>: Download a file from the server given the specified path

        - put     <local_file_path> <remote_file_path>: Upload a file to the server

        - cache   <on/off>: Enable or disable file caching on the server

        - help    : Display help information about available commands

        - exit    : Disconnect from the server and exit the application


High Level Description of Client-Server Model

    (1) Client Server Model:
        - Client: Initiates a connection to the server to perform file operations.
        - Server: Listens for incoming connenctions and responds to client requests.

    (2) Connection Establishment:
        - The client establishes an SSH connection to the server using its IP address
        and port (usually port 22).
        - Once the SSH connection is established, the SFTP subsystem is initiated over
        this connection.

    (3) Authentication:
        - The client authenticates with the server using credentials (username/passeword).

    (4) File Operations:
        - After successful authentication, the client can perform various file operations 
        such as uploading, downloading, renaming, deleting files, and listing directories.


SFTP Explained

    (1) Sockets:
        - SFTP uses underlying SSH protocol which relies on TCP sockets.
        - The server creates a TCP socket to listen for incoming connections on a specific port.
        - The client creates a TCP socket to connect to the server's socket using the server's IP address
        and port.

    (2) IP Address and Port:
        - The server must be bound to an IP address and port to accept incoming connections.
        - The client must know the server's IP address and port to establish a connection,

    (3) Defining Endpoints:
        - Server Endpoint: Defined by the IP address (or hostname) and the port number where the server listens for incoming connections.
        - Client Endpoint: Definedby the client's IP address and port used to initiate the connection. 
        This is typically manages by the OS.

    (4) Creating a Socket:
        - Both the server and client create TCP sockets.
        - The server binds its socket to a specific IP address and port and listens for incoming 
        connections
        - The client connects its socket to the server's IP address and port. 

    (5) Handling Connections:
        - When a client connects, the server accepts the connection, creating a new session to handle
        this specific client's request.
        - The SSH handshake is performed to establish a secure connection.
        - The SFTP subsystem is then initiated within this secure channel. 