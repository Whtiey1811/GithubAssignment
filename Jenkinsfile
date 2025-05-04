pipeline {
    agent any
    stages {
        stage('Checkout') {
            steps {

                git 'https://github.com/Whtiey1811/GithubAssignment'
            }
        }
        stage('Build') {
            steps {

                bat 'make'
            }
        }
        stage('Test') {
            steps {

                echo 'Running tests...'
            }
        }
        stage('Upload to Nexus') {
            steps {
                withCredentials([usernamePassword(credentialsId: 'nexus-creds', passwordVariable: 'NEXUS_PASSWORD', usernameVariable: 'NEXUS_USERNAME')]) {
                    sh '''
                        curl -u $NEXUS_USERNAME:$NEXUS_PASSWORD --upload-file target/your-artifact-name.jar http://your-nexus-repository-url/repository/your-repository-name/
                    '''
                }

            }
        }
    }
}
