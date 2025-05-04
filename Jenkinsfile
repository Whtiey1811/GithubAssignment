pipeline {
    agent any
    environment {
        // Nexus credentials (configured in Jenkins as 'nexus-creds')
        NEXUS_CREDS = credentials('nexus-creds')
        NEXUS_URL = 'http://localhost:8081/repository/cpp-artifacts'
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
                bat 'dir'  // Show files before build
                bat 'make' // Build parsexml.exe
                echo "Build complete, listing output"
                bat 'dir'
            }
        }

        stage('Test') {
            steps {
                echo 'Running tests...'
                bat 'parsexml.exe catalog.xml'
            }
        }

        stage('Upload to Nexus') {
            steps {
                echo "Uploading parsexml.exe to Nexus"
                // Ensure the file is present and then upload
                bat '''
                curl -v -u %NEXUS_CREDS_USR%:%NEXUS_CREDS_PSW% --upload-file parsexml.exe ^
                %NEXUS_URL%/parsexml.exe
                '''
            }
        }
    }
}
