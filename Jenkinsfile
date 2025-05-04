pipeline {
    agent any
    environment {
        NEXUS_CREDS = credentials('nexus-creds')  // Use your configured ID in Jenkins
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
                bat 'dir'             // Shows current directory (for debug)
                bat 'make'            // Builds target/myprogram.exe
                echo "Build completed"
                bat 'dir target'      // Show contents of target folder
            }
        }
        stage('Test') {
            steps {
                echo 'Running tests... (none implemented)'
            }
        }
        stage('Upload to Nexus') {
            steps {
                echo "Uploading build to Nexus"
                sh """
                    curl -v -u ${NEXUS_CREDS_USR}:${NEXUS_CREDS_PSW} --upload-file target/myprogram.exe \
                    ${NEXUS_URL}/myprogram.exe
                """
            }
        }
    }
}
