pipeline {
    agent any
    environment {
        // Define your Nexus credentials (username and password)
        NEXUS_CREDS = credentials('nexus-creds')  // Ensure you are using the correct credentials ID
        NEXUS_URL = 'http://localhost:8081/repository/cpp-artifacts/'
    }
    stages {
        stage('Checkout') {
            steps {
                echo "Checking out repository"
                git 'https://github.com/Whtiey1811/GithubAssignment'
            }
        }
        stage('Build') {
            steps {
                echo "Running make command"
                bat 'dir'  // Check the directory contents before running make
                bat 'make'  // Run make to build the project
                echo "Listing directory contents after make"
                bat 'dir'  // Check the directory contents after running make
            }
        }
        stage('Test') {
            steps {
                echo 'Running tests...'
            }
        }
        stage('Upload to Nexus') {
            steps {
                echo "Uploading build to Nexus"
                sh """
                    curl -u ${NEXUS_CREDS_USR}:${NEXUS_CREDS_PSW} --upload-file target/myprogram.exe \
                        ${NEXUS_URL}/myprogram.exe
                """
            }
        }
    }
}

