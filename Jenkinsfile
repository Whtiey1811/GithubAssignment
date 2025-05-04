pipeline {
    agent any
    environment {
        NEXUS_CREDS = credentials('nexus-creds')  // Jenkins credential with admin user/pass
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
                bat 'dir'
                bat 'make'
                echo "Build complete"
            }
        }
        stage('Upload to Nexus') {
            steps {
                echo "Uploading build to Nexus"
                sh """
                    curl -v -u ${NEXUS_CREDS_USR}:${NEXUS_CREDS_PSW} --upload-file parsexml.exe \\
                        ${NEXUS_URL}/parsexml.exe
                """
            }
        }
    }
}
